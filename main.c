//
//  main.c
//  CTdatabase
//
//  Created by Khoa Minh on 11/28/20.
//  Copyright © 2020 Khoa Minh. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


struct city
{
    // taking name of the city as 20 char length
   char name[20];
   int x;
   int y;
   struct city * next;
};
struct city* newcity(char name[20],int x,int y)
{
  struct city*newct = (struct city*)malloc(sizeof(struct city));
  strcpy(newct->name,name);
  newct->x = x;
  newct->y = y;
  newct->next = NULL;
  return newct;
}

// we are going to make insert function
void insert(struct city** start, char name[20],int x,int y)
{
struct city * temp = *start;
struct city *newct = newcity(name,x,y);
if(*start == NULL)
{
    *start = newct;
    return ;
}
else
{
    // we have to go to the end and insert at the end;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next=newct;
}
return ;
}
// search by name
 struct city * searchByName(struct city** start,char name[20])
 {
      struct city * temp = *start;
      while((*start)->next!=NULL)
      {
        if(strcmp((*start)->name,name)==0)
        {
            return *start;
        }
        *start = (*start)->next;
      }
      return NULL;
 }
 

//search by coordinate.
struct city * searchByCoor(struct city **start,int x,int y)
{

   while((*start)->next)
   {
      if((*start)->x==x && (*start)->y == y)
      {
          return *start;
      }
   }
return NULL;
}



// this is the function when you want to delete record by the name of the of the city.
void deleteByname(struct city** start,char name[20])
{
  struct city* temp = *start;
  struct city * searchCity= searchByName(&temp,name);
  if(searchCity!=NULL)
  {
    while(temp->next!=searchCity)
    {
        temp = temp->next;
    }
    if(searchCity->next ==NULL)
    {
        free(searchCity);
        temp->next =NULL;
    }
    else
    {
        struct city * deleted = searchCity;
        temp->next = searchCity->next;
        free(deleted);
    }
  }
}
// function that delete data by coordinates.
void deleteByCoor(struct city ** start, int x,int y)
{
 struct city* temp = *start;
  struct city * searchCity= searchByCoor(&temp,x,y);
  if(searchCity!=NULL)
  {
    while(temp->next!=searchCity)
    {
        temp = temp->next;
    }
    if(searchCity->next ==NULL)
    {
        free(searchCity);
        temp->next =NULL;
    }
    else
    {
        struct city * deleted = searchCity;
        temp->next = searchCity->next;
        free(deleted);
    }
  }
}

float distance(int x,int y,int x1,int y1)
{
  return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}

void printAllRecord(struct city** start,int x,int y,int dist)
{
  struct city* temp = *start;
  while(temp->next!=NULL)
{
   if(distance(x,y,temp->x,temp->y)<=dist)
   {
       printf("%s %d %d",temp->name,temp->x,temp->y);
   }
   temp=temp->next;
}
}

int main() {
struct city* start = NULL;
// for calling insert
    //void insert(start, name, x, y);
// for deleting the city.
    //deleteByName(start,nameof city);
// for print the range of city
//printAllRecord(start,x axis,y axis,range);

return 0;
}
