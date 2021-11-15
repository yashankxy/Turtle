
#include "imgUtils.c"

// This lets the driver code override the image size if it needs to. Make sure 
// you don't hard-code these values anywhere!
#ifndef SIZEX
  #define SIZEX 512
  #define SIZEY 512
#endif 

/*---------------------------------------------------------------------------*/

/**
 * This struct contains one node of the linked list, which represents a single 
 * command to the Turtle. It's field should include:
 * 
 *  - cmd   : A char array of size 10 holding the command name
 * 
 *  - val   : An integer that stores a parameter for the command (like forward,
 *            backward and colour). 
 * 
 *  - next  : A pointer to a struct of the same type, this is used for the 
 *            linked list
 * 
 * //: Complete this struct definition
 ****/

typedef struct cmdnode {
  char cmd[10];
  int val;
  struct cmdnode *next;
  struct cmdnode *loop_head;
}CmdNode;

/*---------------------------------------------------------------------------*/

CmdNode *newCmdNode(char cmd[10], int val) {
  /** 
   * This function allocates a new CmdNode struct and initializes it's values 
   * based on the input paramaters given. The next pointer is always 
   * initialized to NULL.
   * 
   * If the 'cmd' parameter is not a correct command, then print
   * "Invalid command.\n" and return NULL.
   * 
   * Note that we will always pass in a value here, even if the 
   * command doesn't need one. In this case, we can just ignore 
   * it. It saves us from having to make separate functions to 
   * deal with this.
   * 
   * //: Implement this function
   */
    int flag =0;
    CmdNode *new_node = (CmdNode*)malloc(sizeof(CmdNode));
        if(new_node == NULL){
            printf("\n ERROR: Unable to allocate memory.");
            }
    new_node->next = NULL;

    if (strcmp(cmd, "forward")==0)
    {
      flag =1;
    }
    
    else if (strcmp(cmd, "backward")==0)
    {
      flag =1;
    }
    
    else if (strcmp(cmd, "colour")==0)
    {
      flag =1;
    }
    else if (strcmp(cmd, "penup")==0)
    {
      flag =1;
    }
    else if (strcmp(cmd, "pendown")==0)
    {
      flag =1;
    }
    else if (strcmp(cmd, "right")==0)
    {
      flag =1;
    }
    else if (strcmp(cmd, "left")==0)
    {
      flag =1;
    }
     else if (strcmp(cmd, "loop")==0)
    {
      flag =1;
    }

    if(flag==0)
    { 
      printf("Invalid command.\n");
      return NULL;
    }
    else
    {
      strcpy(new_node->cmd, cmd); 
      new_node->val =val;
      new_node->loop_head=NULL;
      return new_node;
    }


}

/*---------------------------------------------------------------------------*/

void printCommandList(CmdNode *head) {
  /**
   * This function prints out each command in the linked list one after the 
   * other. Each command MUST also have a line number printed before it, this 
   * is what you will be using to modify / delete them. To do this, initialize 
   * a counter and then increment it for each command.
   * 
   * Depending on whether or not the command needs an additional value 
   * (like forward, backward and colour), use one of the following statements 
   * to print out the information for each node: 
   *            [ The format is "linenumber: command value" ]
   * 
   * printf("%3d: %s %d\n", ... );     [With a value]
   * 
   * printf("%3d: %s\n", ... );        [Without a value]
   * 
   * Obviously, you also need to pass in the correct parameters to the print 
   * function yourself, this is just so you have the correct format.
   * 
   * //: Implement this function
   */
  int counter = 0;
  CmdNode* temp = head;
  CmdNode* looptemp =head->loop_head;
  for(temp = head; temp!= NULL; temp=temp->next)
  {
   
    if(strcmp(temp->cmd, "forward") == 0||strcmp(temp->cmd, "colour") == 0||strcmp(temp->cmd, "backward") == 0)  //! check 
    {
      printf("%3d: %s %d\n", counter, temp->cmd, temp->val);
    }
    else if (strcmp(temp->cmd, "pendown") == 0||strcmp(temp->cmd, "penup") == 0||strcmp(temp->cmd, "right") == 0 ||strcmp(temp->cmd, "left") == 0)
    {
      printf("%3d: %s\n", counter, temp->cmd);
    }
    else if (strcmp(temp->cmd, "loop") == 0)
    {
      looptemp = temp->loop_head;
      printf("%3d: %s %d\n", counter, temp->cmd, temp->val);
      while(looptemp!=NULL)
      {
        counter++;
        if(strcmp(looptemp->cmd, "forward") == 0||strcmp(looptemp->cmd, "colour") == 0||strcmp(looptemp->cmd, "backward") == 0)  //! check 
        {
          printf("%3d:   %s %d\n", counter, looptemp->cmd, looptemp->val);
        }
        else
        {
          printf("%3d:   %s\n", counter, looptemp->cmd);
        }  
        looptemp = looptemp->next;
      }
    }
    
    counter++;
  }


  //return;
}

/*---------------------------------------------------------------------------*/

void queryByCommand(CmdNode *head, char cmd[10]) {
  /**
   * This function looks for commands in the linked list that match the input 
   * query. It prints them out in the same format as the printCommandList() 
   * function.
   * 
   * Make sure that the line number of the commands that match is the same as 
   * the line number that would be printed by the printCommandList() function.
   * 
   * --------------------------------------------------------------------------
   * 
   * For instance, if your printCommandList function outputs
   * 
   *    0: penup
   *    1: forward 200
   *    2: right
   *    3: forward 50
   * 
   * Then, if this function is called with the same list and cmd = "forward", 
   * then your output here should be
   * 
   *    1: forward 200
   *    3: forward 50
   * 
   * //: Implement this function
   */
  
   int counter = 0;
  
  CmdNode* temp =NULL;
  CmdNode* looptemp = head->loop_head;
  for(temp = head; temp!= NULL; temp=temp->next)
  {
    if (strcmp(temp->cmd, cmd)==0)
    {
      if(strcmp(temp->cmd, "forward") == 0||strcmp(temp->cmd, "colour") == 0||strcmp(temp->cmd, "backward") == 0)  //! check 
    {
      printf("%3d: %s %d\n", counter, temp->cmd, temp->val);
    }
      else if (strcmp(temp->cmd, "pendown") == 0||strcmp(temp->cmd, "penup") == 0||strcmp(temp->cmd, "right") == 0 ||strcmp(temp->cmd, "left") == 0)
    {
      printf("%3d: %s\n", counter, temp->cmd);
    }
      
    
    
    // if(strcmp(temp->cmd, "forward") == 0||strcmp(temp->cmd, "colour") == 0||strcmp(temp->cmd, "backward") == 0)  //! check 
    // {
    //   printf("%3d: %s %d\n", counter, temp->cmd, temp->val);
    // }
    // else{
    //   printf("%3d: %s\n", counter, temp->cmd);
    // }
    }
    if (strcmp(temp->cmd, "loop") == 0)
    {
      looptemp = temp ->loop_head;
      //printf("%3d: %s %d\n", counter, temp->cmd, temp->val);
      while(looptemp!=NULL)
      {
        counter++;
        if (strcmp(looptemp->cmd , cmd) == 0)
        {
          if(strcmp(looptemp->cmd, "forward") == 0||strcmp(looptemp->cmd, "colour") == 0||strcmp(looptemp->cmd, "backward") == 0)  //! check 
          {
            printf("%3d: %s %d\n", counter, looptemp->cmd, looptemp->val);
          }
        else
          {
            printf("%3d: %s\n", counter, looptemp->cmd);
          }
        }  
        looptemp = looptemp->next;
      }
    }
    counter++;
  }
  
   
   
    counter++;
  }

/*---------------------------------------------------------------------------*/

int countCommands(CmdNode *head) {
  /**
   * This function counts and returns the length of the linked list. It 
   * requires list traversal.
   * 
   * //: Implement this function
   */
  int count;
  CmdNode *node=head;
  CmdNode *loop_head=head;
  for(count=0; node!=NULL ;count++)
  {
    if (strcmp(node->cmd, "loop")==0)
    {
      loop_head = node->loop_head;
      while(loop_head!= NULL)
      {
        loop_head = loop_head->next;
        count++;
      }
    }
    node = node->next;
  }
  return count;
}

/*---------------------------------------------------------------------------*/

CmdNode *insertCommand(CmdNode *head, CmdNode *new_CmdNode) {
  /**
   * This function inserts the node new_CmdNode *at the tail* of the linked 
   * list. (You are adding a command at the end).
   * 
   * If head == NULL, then the linked list is still empty.
   * 
   * It returns a pointer to the head of the linked list with the new node 
   * added into it.
   * 
   * //: Implement this function
   */
  CmdNode *p=head;
  if (head == NULL)
  {
    head =new_CmdNode; // if head is null then insert new node at head
    return head;
  }
  else{
    while (p->next != NULL)
    {
      /* code */
      p= p->next; // bringing the pointer at the tail
    }
    p->next=new_CmdNode;  // adding newnode
    return head; 
  }

  //return NULL;
}

/*---------------------------------------------------------------------------*/

CmdNode *insertCommandBefore(CmdNode *head, CmdNode *new_CmdNode, int cmdNum) {
  
  CmdNode *temp =head;
  
  if (cmdNum>=countCommands(head))
  {
    printf("Invalid Command Number.\n");
    return head;
  }
  if (cmdNum ==0)
  {
    new_CmdNode-> next = temp; 
    head= new_CmdNode;
    return head;
  }
  else{
       for (int i=1 ; i<cmdNum; i++)  // looping untill i <position  //? check whether conditoin is cmdNum-1 or not
        {
          temp = temp->next;  // temp saves the position (address) of previous node (node after which new pointer is to be inserted )
        }
        new_CmdNode->next =temp->next;  // New node (Pointer) now contains the address inside previous temp i.e next node (connecting new node with next node)
        temp->next= new_CmdNode;       // Now the previous temp contains the address of new node (connecting new node with previous node)
        return head;
  }

  return NULL;

  return NULL;
  
  
  
  /**
   * This function inserts a new node *before* a given Node in the linked list. 
   * 
   * 'cmdNum' is an integer that corresponds to the line number of a command 
   * from the printCommandList() function. Your task is to insert new_CmdNode 
   * *before* the corresponding node in the linked list.
   *
   * --------------------------------------------------------------------------
   *  
   * For instance, if your initial list was
   * 
   *    0: penup
   *    1: forward 200
   *    2: right
   *    3: forward 50
   * 
   * And you added "pendown" before cmdNum = 2, then you will have
   * 
   *    0: penup
   *    1: forward 200
   *    2: pendown
   *    3: right
   *    4: forward 50
   * 
   * --------------------------------------------------------------------------
   * 
   * If there is no command with the given cmdNum (cmdNum >= list size), 
   * then print "Invalid Command Number.\n" to the screen and *do not* 
   * insert the new node.
   * 
   * Returns a pointer to the head of the linked list with the new node added 
   * into it.
   * 
   * //: Implement this function
   */
  
}

/*---------------------------------------------------------------------------*/

void insertCommandLoop(CmdNode *loop_node,CmdNode *new_node)
{
/** 
   * Add a function called insertCommandLoop(). This function will be used to insert
   * a command at the end of the linked list for a 'loop' node. It will take in 2 
   * parameters, the first will be a pointer to the loop node, and the second will 
   * be a pointer to the new command node that you have to insert into the loop. 
   * This function should not return anything, but just update the linked list at 
   * the loop node.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* NOTE: When you insert a 'loop' command into list using the interactive
*       driver, it will then prompt you to enter all the commands that are
*       a part of the loop one by one. Alternatively, you can write all your
*       commands in a text file (look at box-pro.txt) and then load them in
*       through the interactive driver.
*
*       We will NOT be worrying about nested loops for now, you will learn how 
*       to handle that later in the course! 
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

   * 
   * TODO: Implement this function
   */
  CmdNode *loop_head = loop_node->loop_head;
  //CmdNode *node=loop_head;
  CmdNode *temp = loop_head;
  if (loop_node->loop_head == NULL)
  {
    // strcpy(loop_node->loop_head->cmd ,new_node->cmd); // if head is null then insert new node at head
    // loop_node->loop_head->val = new_node->val;
    // loop_node->loop_head->next =NULL;
    // loop_node->loop_head->loop_head =NULL;
    loop_node->loop_head = new_node;
    //return loop_head;
  }
  else
  {

    while (temp->next != NULL)
    {
      /* code */
      temp= temp->next; // bringing the pointer at the tail
    }
    // strcpy(temp->next->cmd ,new_node->cmd); // if head is null then insert new node at head
    // temp->next->val= new_node->val;
    // temp->next->next =NULL;
    // temp->next->loop_head =NULL;
      temp->next = new_node;  // adding newnode
    //return loop_head; 
    
  }
}

/*---------------------------------------------------------------------------*/

void updateCommand(CmdNode *head, int cmdNum, char cmd[10], int val) {
  /**
   * This function updates a specific node in the linked list based on the 
   * input parameters.
   * 
   * 'cmdNum' is an integer that corresponds to the line number of a command 
   * from the printCommandList() function. Your task is to update the 'cmd' and 
   * 'val' fields of this node.
   * 
   * If there is no command with the given cmdNum, then print 
   * "Invalid Command Number.\n" to the screen, and if 'cmd' is not a correct 
   * command, then print "Invalid command.\n". In both these cases, do *not* 
   * modify the list.
   * 
   * //: Implement this function
   */
  int flag=0;
  int num=0;
  if (strcmp(cmd, "forward")==0)
  {
    flag++;
  }
  else if (strcmp(cmd, "backward")==0)
  {
    flag++;
  }
  else if (strcmp(cmd, "right")==0)
  {
    flag++;
  }
  else if (strcmp(cmd, "left")==0)
  {
    flag++;
  }
  else if (strcmp(cmd, "colour")==0)
  {
    flag++;
  }
  else if (strcmp(cmd, "pendown")==0)
  {
    flag++;
  }
  if(flag ==0 || cmdNum >= countCommands(head))
  {
    printf("Invalid command.\n");
    return;
  }
  else{
    CmdNode *temp =head;
    for(num=0; num<cmdNum && temp !=NULL; num++)
    {
      temp=temp->next;
    }
    strcpy(temp->cmd,cmd);
    temp->val =val;
  }

  


  //return ;
}

/*---------------------------------------------------------------------------*/


CmdNode *deleteCommand(CmdNode *head, int cmdNum) {
  /**
   * This function deletes the node from the linked list that corresponds to 
   * the line number cmdNum. If there is no command with the given cmdNum, then 
   * the function does nothing.
   * 
   * Returns a pointer to the head of the linked list (which may have changed 
   * as a result of the deletion)
   *
   * //: Implement this function
   */
  CmdNode *temp =head;
  CmdNode *remove =NULL;
  
  if(head == NULL)
  {
    return head;
  }
  if(cmdNum ==0)
  {
    temp= head->next;
    free(head);
    return temp;
  }
  temp =head;
  int i;
    for (i=0 ; temp->next!=NULL && i<cmdNum-1; i++)  // looping untill i <position  //? check whether conditoin is cmdNum-1 or not
        {
          temp = temp->next;  // temp saves the position (address) of previous node (node after which new pointer is to be inserted )
        }
    if(i ==cmdNum-1)
      {
          remove=temp->next;  // New node (Pointer) now contains the address inside previous temp i.e next node (connecting new node with next node)
        temp->next= temp->next->next;       // Now the previous temp contains the address of new node (connecting new node with previous node)
        free(remove);
      }
      return head;
  
// CmdNode *cur = head;
//     CmdNode*prv = NULL;
//     int count;
//     if (head == NULL)           
//     {
//         return NULL;
//     }
    
//     while(count < cmdNum-1)
//     {
//         if (cur->next == NULL)
//         {
//             return NULL;   
//         }
//         else
//         {
//             prv = cur;
//             free(prv);
//             cur = cur->next;
//         }
//     }
//     if (cur == head)
//         {
//           cur = head->next;
//           free(head);
//           return cur;
//         }
//         else
//         {
//             prv->next = cur->next; 
//         }
//         return cur;
  

  //return NULL;
}

/*---------------------------------------------------------------------------*/


CmdNode *deleteCommandList(CmdNode *head) {
  /**
   * This function deletes the linked list of commands, releasing all the 
   * memory allocated to the nodes in the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   * 
   * //: Implement this function
   */
  CmdNode *temp = NULL;
  CmdNode *temp_loop = NULL;
  CmdNode *delete = head;
  CmdNode *delete_loop;
  while(delete!=NULL)
  {
    temp = delete->next;
    
    if(temp != NULL && strcmp(temp->cmd , "loop") == 0)
    {
      delete_loop = temp->loop_head;
      while(delete_loop != NULL)
      { 
        temp_loop = delete_loop->next;
        free(delete_loop);
        delete_loop = temp_loop;
      }
    }

    free(delete);
    delete = temp;
  }
  head = NULL;
  return NULL;
}


/*---------------------------------------------------------------------------*/

void run(Image *im, CmdNode *head, int *endX, int *endY) 
{
  /**
   * This function runs the list of commands to move the turtle around and draw 
   * the image, and returns the final position of the turtle in the variables 
   * endX and endY.
   * 
   * --------------------------------------------------------------------------
   * 
   * NOTE: In the image we work with, the top-left pixel is (0,0),
   *       - x increases as you go right, up till SIZEX-1
   *       - y increases as you go down, up till SIZEY-1
   * 
   *                 (0,0)                 (SIZEX-1, 0)
   *                   x------------------------x
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   |          IMAGE         |
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   x------------------------x
   *             (0, SIZEY-1)            (SIZEX-1, SIZEY-1)
   * 
   * The image is in grayscale (black and white), so the colours are numbers 
   * from [0-255] where 0 is black, 255 is white, and the values in between 
   * are varying levels of gray.
   * 
   * You need to understand how the (x,y) values are stored so you know how 
   * they should be updated when you move (down means y increases, etc). You do 
   * not need to use the 'im' variable for anything other than passing it into 
   * the drawLine() function described below.
   * 
   * --------------------------------------------------------------------------
   * 
   * Here's the setup - There is a turtle (with a pen) that walks along the 
   * image. When the pen is down (on the paper), it draws a line along the path 
   * that it walks on. (If you want to play around with this, consider looking 
   * at the `turtle` library in python!)
   * 
   * The turtle initially starts at pixel (0, 0) [at the top left], 
   * facing right (in the positive x direction). The pen starts off
   * as `down`, with the default colour being black (0).
   * 
   * You need to go through the linked list and 'run' the commands to keep 
   * track of the turtles position, and draw the appropriate lines. Here is 
   * what each command should do:
   * 
   *  - penup          : Put the pen up (stop drawing)
   *  - pendown        : Put the pen down (start / continue drawing)
   *  - colour <val>   : Draw lines in colour <val> from now on
   *  - forward <val>  : Move the turtle forward <val> steps (pixels) 
   *                     in the direction it is facing.
   *  - backward <val> : Same as above, except move backwards
   *  - right          : Turn the turtle to the right by 90 degrees
   *  - left           : Turn the turtle to the left by 90 degrees
   * 
   * NOTE: Make sure that you do *not* go outside the image. For this, set the 
   * maximum and minimum values of x and y to be 0 and SIZEX-1 / SIZEY-1 
   * respectively.
   * 
   * For instance, if the turtle is at (0,0) facing right, and your command is
   * `forward 100000`, it will only go forward till (SIZEX-1, 0), and end 
   * up at the rightmost pixel in that row.
   * 
   * IMPORTANT: Once you are done with all the commands, make sure you save the 
   * final (x,y) location of the turtle into the variables endX and endY.
   * 
   * --------------------------------------------------------------------------
   * 
   * We have already implemented a drawLine() function (in imgUtils.c) which 
   * you should use to actually draw the lines. It takes in the following:
   * 
   *      - a pointer to an image struct (use 'im')
   *      - (x,y) location of start point
   *      - (x,y) location of end point
   *      - a colour to draw the line in [0-255]
   *          
   * Note that this function only draws horizontal and vertical lines, so 
   * either the x values or the y values of both points must be the same. 
   * Both these points *must* also be within the image. 
   *          [ 0 <= x < SIZEX,  0 <= y < SIZEY ]
   * 
   * 
   * TODO: Implement this function
   */

    CmdNode *temp = head;
    char tempcmd[10];
    int tempval;
    int x1;
    *endX =0;
    int y1;
    *endY =0;
    int a;
    int turn = 1;
    // Inside loop
    int colour =0;
    CmdNode *temploop= NULL;

    // =0;
  while(temp != NULL)
  {
    strcpy(tempcmd, temp->cmd);
    tempval = temp->val;
    temploop = temp->loop_head;
    
    if(strcmp(tempcmd , "penup") == 0)
    {
      a = 0;
    }
    else if (strcmp(tempcmd , "pendown") == 0)
    {
      a=1;
    }
    
    if (a==0)
    {
      if(strcmp(tempcmd , "colour")==0)
      {
        colour = tempval;
      }
      if (strcmp(tempcmd , "right") ==0)            //!!  <----------------------
      {
        turn+=1;
      }
      if(strcmp(tempcmd , "left")==0)               //!!  <----------------------
      {
        turn+=3;
      }
      if (turn>4)                                      //!!  <----------------------
      {
        turn-=4;
      }
      
      // if forward
      if(strcmp(tempcmd , "forward") == 0)
          {
          
          // ? if pointing forward check  
          if (turn == 1)
              {
                // x1= *endX;
                // y1 = *endY;

                *endX = *endX + tempval; // move right or left (ACCORDING TO THE COORDINATES) moving along X axis, not right/ left according to above
                *endY = *endY;
                // if out of boundary then 
                  if(*endX > SIZEX-1)
                    {
                      *endX = SIZEX-1;
                    } 
              // drawline ()
              //drawLine(im , x1, y1 , *endX , *endY, colour);
              }

          // ? if pointing backwards check....
          if (turn == 3)
            {
            //  x1= *endX;
            //  y1 = *endY;

                *endX = *endX - tempval; // move right or left (ACCORDING TO THE COORDINATES) moving along X axis, not right/ left according to above 
                *endY = *endY;
                // if out of boundary then 
              if(*endX < 0)
              {
                *endX = 0;
              } 
              // drawline ()
              //drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          
          // ? if pointing RIGHT check....
          if (turn == 2)
          {
            //  x1= *endX;
            //  y1 = *endY;

                *endX = *endX ; 
                *endY = *endY + tempval; // move up or down (here it means righ ot left)
                // if out of boundary then 
              if(*endY > SIZEY-1)
              {
                *endY = SIZEY -1;
              } 
              // drawline ()
              //drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          
          // ? if pointing LEFT check....
          if (turn == 4)
          {
            //  x1= *endX;
            //  y1 = *endY;

                *endX = *endX ; 
                *endY = *endY - tempval; // move up or down (here it means righ ot left)
                // if out of boundary then 
              if(*endY < 0)
              {
                *endY = 0;
              } 
              // drawline ()
              //drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          }  

      // if backward
      if(strcmp(tempcmd , "backward") == 0)
          {
          // ? if pointing backwards check  
          if (turn == 1)
              {
                // x1= *endX;
                // y1 = *endY;
                
                *endX = *endX - tempval; 
                *endY = *endY;
                // if out of boundary then 
              if(*endX < 0)
              {
                *endX = 0;
              }
                
              // drawline ()
              //drawLine(im , x1, y1 , *endX , *endY, colour);
              }

          // ? if pointing forward check....
          if (turn == 3)
            {
            //  x1= *endX;
            //  y1 = *endY;

                
              *endX = *endX + tempval; 
              *endY = *endY;
                // if out of boundary then 
                  if(*endX > SIZEX-1)
                    {
                      *endX = SIZEX-1;
                    } 
              // drawline ()
              //drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          
          // ? if pointing LEFT check....
          if (turn == 2)
          {
            //  x1= *endX;
            //  y1 = *endY;

              *endX = *endX ; 
              *endY = *endY - tempval; // move up or down (here it means righ ot left)
                // if out of boundary then 
              if(*endY < 0)
              {
                *endY = 0;
              } 
              // drawline ()
              //drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          
          // ? if pointing RIGHT check....
          if (turn == 4)
          {
            //  x1= *endX;
            //  y1 = *endY;

              *endX = *endX ; 
              *endY = *endY + tempval; // move up or down (here it means righ ot left)
                // if out of boundary then 
              if(*endY > SIZEY-1)
              {
                *endY = SIZEY -1;
              } 
                
              // drawline ()
              //drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          }    

    }
    
    else if(a==1)
    {

      if(strcmp(tempcmd , "colour") == 0)
      {
        colour = tempval;
      }
      if (strcmp(tempcmd , "right") == 0)            //!!  <----------------------
      {
        turn+=1;
      }
      if(strcmp(tempcmd , "left") == 0)               //!!  <----------------------
      {
        turn+=3;
      }
      if (turn>4)                                      //!!  <----------------------
      {
        turn-=4;
      }
      
      // if forward
      if(strcmp(tempcmd , "forward") == 0)
          {
          
          // ? if pointing forward check  
          if (turn == 1)
              {
                x1= *endX;
                y1 = *endY;

                *endX = *endX + tempval; // move right or left (ACCORDING TO THE COORDINATES) moving along X axis, not right/ left according to above
                *endY = *endY;
                // if out of boundary then 
                  if(*endX > SIZEX-1)
                    {
                      *endX = SIZEX-1;
                    } 
              // drawline ()
              drawLine(im , x1, y1 , *endX , *endY, colour);
              }

          // ? if pointing backwards check....
          if (turn == 3)
            {
             x1= *endX;
             y1 = *endY;

                *endX = *endX - tempval; // move right or left (ACCORDING TO THE COORDINATES) moving along X axis, not right/ left according to above 
                *endY = *endY;
                // if out of boundary then 
              if(*endX < 0)
              {
                *endX = 0;
              } 
              // drawline ()
              drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          
          // ? if pointing RIGHT check....
          if (turn == 2)
          {
             x1= *endX;
             y1 = *endY;

                *endX = *endX ; 
                *endY = *endY + tempval; // move up or down (here it means righ ot left)
                // if out of boundary then 
              if(*endY > SIZEY-1)
              {
                *endY = SIZEY -1;
              } 
              // drawline ()
              drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          
          // ? if pointing LEFT check....
          if (turn == 4)
          {
             x1= *endX;
             y1 = *endY;

                *endX = *endX ; 
                *endY = *endY - tempval; // move up or down (here it means righ ot left)
                // if out of boundary then 
              if(*endY < 0)
              {
                *endY = 0;
              } 
              // drawline ()
              drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          }  

      // if backward
      if(strcmp(tempcmd , "backward") == 0)
          {
          // ? if pointing backwards check  
          if (turn == 1)
              {
                x1= *endX;
                y1 = *endY;
                
                *endX = *endX - tempval; 
                *endY = *endY;
                // if out of boundary then 
              if(*endX < 0)
              {
                *endX = 0;
              }
                
              // drawline ()
              drawLine(im , x1, y1 , *endX , *endY, colour);
              }

          // ? if pointing forward check....
          if (turn == 3)
            {
             x1= *endX;
             y1 = *endY;

                
              *endX = *endX + tempval; 
              *endY = *endY;
                // if out of boundary then 
                  if(*endX > SIZEX-1)
                    {
                      *endX = SIZEX-1;
                    } 
              // drawline ()
              drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          
          // ? if pointing LEFT check....
          if (turn == 2)
          {
             x1= *endX;
             y1 = *endY;

              *endX = *endX ; 
              *endY = *endY - tempval; // move up or down (here it means righ ot left)
                // if out of boundary then 
              if(*endY < 0)
              {
                *endY = 0;
              } 
              // drawline ()
              drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          
          // ? if pointing RIGHT check....
          if (turn == 4)
          {
             x1= *endX;
             y1 = *endY;

              *endX = *endX ; 
              *endY = *endY + tempval; // move up or down (here it means righ ot left)
                // if out of boundary then 
              if(*endY > SIZEY-1)
              {
                *endY = SIZEY -1;
              } 
                
              // drawline ()
              drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          }    

     
    //temp = temp->next;
  }
 
    if (strcmp(tempcmd , "loop")==0)
      {
        int num;
        int z = tempval;
        for(num = 0; num < z ; num++)
        {
          temploop = temp->loop_head;
          while (temploop != NULL)
          {
            strcpy(tempcmd, temploop->cmd);
            tempval = temploop->val;
          
            if(strcmp(tempcmd , "penup") == 0)
            {
              a = 0;
            }
            else if (strcmp(tempcmd , "pendown") == 0)
          {
            a=1;
          }
        
            if (a==0)
    {
      if(strcmp(tempcmd , "colour")==0)
      {
        colour = tempval;
      }
      if (strcmp(tempcmd , "right") ==0)            //!!  <----------------------
      {
        turn+=1;
      }
      if(strcmp(tempcmd , "left")==0)               //!!  <----------------------
      {
        turn+=3;
      }
      if (turn>4)                                      //!!  <----------------------
      {
        turn-=4;
      }
      
      // if forward
      if(strcmp(tempcmd , "forward") == 0)
          {
          
          // ? if pointing forward check  
          if (turn == 1)
              {
                // x1= *endX;
                // y1 = *endY;

                *endX = *endX + tempval; // move right or left (ACCORDING TO THE COORDINATES) moving along X axis, not right/ left according to above
                *endY = *endY;
                // if out of boundary then 
                  if(*endX > SIZEX-1)
                    {
                      *endX = SIZEX-1;
                    } 
              // drawline ()
              //drawLine(im , x1, y1 , *endX , *endY, colour);
              }

          // ? if pointing backwards check....
          if (turn == 3)
            {
            //  x1= *endX;
            //  y1 = *endY;

                *endX = *endX - tempval; // move right or left (ACCORDING TO THE COORDINATES) moving along X axis, not right/ left according to above 
                *endY = *endY;
                // if out of boundary then 
              if(*endX < 0)
              {
                *endX = 0;
              } 
              // drawline ()
              //drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          
          // ? if pointing RIGHT check....
          if (turn == 2)
          {
            //  x1= *endX;
            //  y1 = *endY;

                *endX = *endX ; 
                *endY = *endY + tempval; // move up or down (here it means righ ot left)
                // if out of boundary then 
              if(*endY > SIZEY-1)
              {
                *endY = SIZEY -1;
              } 
              // drawline ()
              //drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          
          // ? if pointing LEFT check....
          if (turn == 4)
          {
            //  x1= *endX;
            //  y1 = *endY;

                *endX = *endX ; 
                *endY = *endY - tempval; // move up or down (here it means righ ot left)
                // if out of boundary then 
              if(*endY < 0)
              {
                *endY = 0;
              } 
              // drawline ()
              //drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          }  

      // if backward
      if(strcmp(tempcmd , "backward") == 0)
          {
          // ? if pointing backwards check  
          if (turn == 1)
              {
                // x1= *endX;
                // y1 = *endY;
                
                *endX = *endX - tempval; 
                *endY = *endY;
                // if out of boundary then 
              if(*endX < 0)
              {
                *endX = 0;
              }
                
              // drawline ()
              //drawLine(im , x1, y1 , *endX , *endY, colour);
              }

          // ? if pointing forward check....
          if (turn == 3)
            {
            //  x1= *endX;
            //  y1 = *endY;

                
              *endX = *endX + tempval; 
              *endY = *endY;
                // if out of boundary then 
                  if(*endX > SIZEX-1)
                    {
                      *endX = SIZEX-1;
                    } 
              // drawline ()
              //drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          
          // ? if pointing LEFT check....
          if (turn == 2)
          {
            //  x1= *endX;
            //  y1 = *endY;

              *endX = *endX ; 
              *endY = *endY - tempval; // move up or down (here it means righ ot left)
                // if out of boundary then 
              if(*endY < 0)
              {
                *endY = 0;
              } 
              // drawline ()
              //drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          
          // ? if pointing RIGHT check....
          if (turn == 4)
          {
            //  x1= *endX;
            //  y1 = *endY;

              *endX = *endX ; 
              *endY = *endY + tempval; // move up or down (here it means righ ot left)
                // if out of boundary then 
              if(*endY > SIZEY-1)
              {
                *endY = SIZEY -1;
              } 
                
              // drawline ()
              //drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          }    

    }
    
            else if(a==1)
    {

      if(strcmp(tempcmd , "colour") == 0)
      {
        colour = tempval;
      }
      if (strcmp(tempcmd , "right") == 0)            //!!  <----------------------
      {
        turn+=1;
      }
      if(strcmp(tempcmd , "left") == 0)               //!!  <----------------------
      {
        turn+=3;
      }
      if (turn>4)                                      //!!  <----------------------
      {
        turn-=4;
      }
      
      // if forward
      if(strcmp(tempcmd , "forward") == 0)
          {
          
          // ? if pointing forward check  
          if (turn == 1)
              {
                x1= *endX;
                y1 = *endY;

                *endX = *endX + tempval; // move right or left (ACCORDING TO THE COORDINATES) moving along X axis, not right/ left according to above
                *endY = *endY;
                // if out of boundary then 
                  if(*endX > SIZEX-1)
                    {
                      *endX = SIZEX-1;
                    } 
              // drawline ()
              drawLine(im , x1, y1 , *endX , *endY, colour);
              }

          // ? if pointing backwards check....
          if (turn == 3)
            {
             x1= *endX;
             y1 = *endY;

                *endX = *endX - tempval; // move right or left (ACCORDING TO THE COORDINATES) moving along X axis, not right/ left according to above 
                *endY = *endY;
                // if out of boundary then 
              if(*endX < 0)
              {
                *endX = 0;
              } 
              // drawline ()
              drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          
          // ? if pointing RIGHT check....
          if (turn == 2)
          {
             x1= *endX;
             y1 = *endY;

                *endX = *endX ; 
                *endY = *endY + tempval; // move up or down (here it means righ ot left)
                // if out of boundary then 
              if(*endY > SIZEY-1)
              {
                *endY = SIZEY -1;
              } 
              // drawline ()
              drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          
          // ? if pointing LEFT check....
          if (turn == 4)
          {
             x1= *endX;
             y1 = *endY;

                *endX = *endX ; 
                *endY = *endY - tempval; // move up or down (here it means righ ot left)
                // if out of boundary then 
              if(*endY < 0)
              {
                *endY = 0;
              } 
              // drawline ()
              drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          }  

      // if backward
      if(strcmp(tempcmd , "backward") == 0)
          {
          // ? if pointing backwards check  
          if (turn == 1)
              {
                x1= *endX;
                y1 = *endY;
                
                *endX = *endX - tempval; 
                *endY = *endY;
                // if out of boundary then 
              if(*endX < 0)
              {
                *endX = 0;
              }
                
              // drawline ()
              drawLine(im , x1, y1 , *endX , *endY, colour);
              }

          // ? if pointing forward check....
          if (turn == 3)
            {
             x1= *endX;
             y1 = *endY;

                
              *endX = *endX + tempval; 
              *endY = *endY;
                // if out of boundary then 
                  if(*endX > SIZEX-1)
                    {
                      *endX = SIZEX-1;
                    } 
              // drawline ()
              drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          
          // ? if pointing LEFT check....
          if (turn == 2)
          {
             x1= *endX;
             y1 = *endY;

              *endX = *endX ; 
              *endY = *endY - tempval; // move up or down (here it means righ ot left)
                // if out of boundary then 
              if(*endY < 0)
              {
                *endY = 0;
              } 
              // drawline ()
              drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          
          // ? if pointing RIGHT check....
          if (turn == 4)
          {
             x1= *endX;
             y1 = *endY;

              *endX = *endX ; 
              *endY = *endY + tempval; // move up or down (here it means righ ot left)
                // if out of boundary then 
              if(*endY > SIZEY-1)
              {
                *endY = SIZEY -1;
              } 
                
              // drawline ()
              drawLine(im , x1, y1 , *endX , *endY, colour);
            }
          }    

     
    //temp = temp->next;
  }
  
            temploop = temploop->next;
          }
        }
    }
  
  temp = temp->next;
  //CmdNode *templop =temp->loop_head;
  //printf("temp->next is %s\n", temp->cmd);
  //printf("templop->next is %s\n", templop->cmd);
  //return;
}
}

/*---------------------------------------------------------------------------*/
// All done!


