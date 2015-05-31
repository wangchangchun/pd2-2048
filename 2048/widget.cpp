#include "widget.h"
#include "ui_play.h"
#include<QKeyEvent>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
widget::widget(QWidget *parent) :
    QWidget(parent),
    gui(new Ui::Form)
{

     gui->setupUi(this);
     gui->win->hide();
     gui->lose->hide();
     gui->people->hide();
     gui->attact->hide();
    max=0;
     point=0;
     round=0;
     for(int i=0;i<16;i++)
     {
         box[i]=0;
     }
     for(int i=0;i<4;i++)
         check[i]=0;
     start();
     paint();
}

widget::~widget()
{
    delete gui;
}

void widget::generate()
{
 round++;
            srand(time(0));
            int r=rand()%10;
            if(round==max/5+10+r)
            {
                 gui->attact->show();
                for(int att=0;att<16;att++)
                {
                    if(box[att]>2)
                        box[att]=box[att]/2;

                }
                round=0;

            }
            if(max==16||max==32||max==128||max==256||max==512||max==1024)
                round=0;
            int newblock=rand()%16;
            while(box[newblock]!=0)
            {
              newblock=rand()%16;
             }
            box[newblock]=2;
            for(int m=0;m<16;m++)
            {
                if(box[m]>max)
                    max=box[m];
            }
            if(max>=32&&max<256)
                gui->monster->setPixmap(QPixmap(":/new/monster.png"));
            else if(max>=256&&max<1024)
                gui->monster->setPixmap(QPixmap(":/new/Qpeople.png"));
            else if(max==1024)
            {
                gui->monster->close();
                gui->people->show();
            }

}

void widget::paint()
{
    for(int i=0;i<16;i++)
    {
    switch(i)
    {
        case 0:
        switch (box[i])
        {
            case 0:gui->B1->setPixmap(QPixmap(":/new/0.png"));break;
            case 2:gui->B1->setPixmap(QPixmap(":/new/2v2.png"));break;
            case 4:gui->B1->setPixmap(QPixmap(":/new/4v2.png"));break;
            case 8:gui->B1->setPixmap(QPixmap(":/new/8v2.png"));break;
            case 16:gui->B1->setPixmap(QPixmap(":/new/16v2.png"));break;
            case 32:gui->B1->setPixmap(QPixmap(":/new/32v2.png"));break;
            case 64:gui->B1->setPixmap(QPixmap(":/new/64v2.png"));break;
            case 128:gui->B1->setPixmap(QPixmap(":/new/128v2.png"));break;
            case 256:gui->B1->setPixmap(QPixmap(":/new/256v2.png"));break;
            case 512:gui->B1->setPixmap(QPixmap(":/new/512v2.png"));break;
            case 1024:gui->B1->setPixmap(QPixmap(":/new/1024v2.png"));break;
            case 2048:gui->B1->setPixmap(QPixmap(":/new/2048v2.png"));break;

        }
    case 1:
    switch (box[i])
    {
        case 0:gui->B2->setPixmap(QPixmap(":/new/0.png"));break;
        case 2:gui->B2->setPixmap(QPixmap(":/new/2v2.png"));break;
        case 4:gui->B2->setPixmap(QPixmap(":/new/4v2.png"));break;
        case 8:gui->B2->setPixmap(QPixmap(":/new/8v2.png"));break;
        case 16:gui->B2->setPixmap(QPixmap(":/new/16v2.png"));break;
        case 32:gui->B2->setPixmap(QPixmap(":/new/32v2.png"));break;
        case 64:gui->B2->setPixmap(QPixmap(":/new/64v2.png"));break;
        case 128:gui->B2->setPixmap(QPixmap(":/new/128v2.png"));break;
        case 256:gui->B2->setPixmap(QPixmap(":/new/256v2.png"));break;
        case 512:gui->B2->setPixmap(QPixmap(":/new/512v2.png"));break;
        case 1024:gui->B2->setPixmap(QPixmap(":/new/1024v2.png"));break;
        case 2048:gui->B2->setPixmap(QPixmap(":/new/2048v2.png"));break;

    }
    case 2:
    switch (box[i])
    {
        case 0:gui->B3->setPixmap(QPixmap(":/new/0.png"));break;
        case 2:gui->B3->setPixmap(QPixmap(":/new/2v2.png"));break;
        case 4:gui->B3->setPixmap(QPixmap(":/new/4v2.png"));break;
        case 8:gui->B3->setPixmap(QPixmap(":/new/8v2.png"));break;
        case 16:gui->B3->setPixmap(QPixmap(":/new/16v2.png"));break;
        case 32:gui->B3->setPixmap(QPixmap(":/new/32v2.png"));break;
        case 64:gui->B3->setPixmap(QPixmap(":/new/64v2.png"));break;
        case 128:gui->B3->setPixmap(QPixmap(":/new/128v2.png"));break;
        case 256:gui->B3->setPixmap(QPixmap(":/new/256v2.png"));break;
        case 512:gui->B3->setPixmap(QPixmap(":/new/512v2.png"));break;
        case 1024:gui->B3->setPixmap(QPixmap(":/new/1024v2.png"));break;
        case 2048:gui->B3->setPixmap(QPixmap(":/new/2048v2.png"));break;

    }
    case 3:
    switch (box[i])
    {
        case 0:gui->B4->setPixmap(QPixmap(":/new/0.png"));break;
        case 2:gui->B4->setPixmap(QPixmap(":/new/2v2.png"));break;
        case 4:gui->B4->setPixmap(QPixmap(":/new/4v2.png"));break;
        case 8:gui->B4->setPixmap(QPixmap(":/new/8v2.png"));break;
        case 16:gui->B4->setPixmap(QPixmap(":/new/16v2.png"));break;
        case 32:gui->B4->setPixmap(QPixmap(":/new/32v2.png"));break;
        case 64:gui->B4->setPixmap(QPixmap(":/new/64v2.png"));break;
        case 128:gui->B4->setPixmap(QPixmap(":/new/128v2.png"));break;
        case 256:gui->B4->setPixmap(QPixmap(":/new/256v2.png"));break;
        case 512:gui->B4->setPixmap(QPixmap(":/new/512v2.png"));break;
        case 1024:gui->B4->setPixmap(QPixmap(":/new/1024v2.png"));break;
        case 2048:gui->B4->setPixmap(QPixmap(":/new/2048v2.png"));break;

    }
    case 4:
    switch (box[i])
    {
        case 0:gui->B5->setPixmap(QPixmap(":/new/0.png"));break;
        case 2:gui->B5->setPixmap(QPixmap(":/new/2v2.png"));break;
        case 4:gui->B5->setPixmap(QPixmap(":/new/4v2.png"));break;
        case 8:gui->B5->setPixmap(QPixmap(":/new/8v2.png"));break;
        case 16:gui->B5->setPixmap(QPixmap(":/new/16v2.png"));break;
        case 32:gui->B5->setPixmap(QPixmap(":/new/32v2.png"));break;
        case 64:gui->B5->setPixmap(QPixmap(":/new/64v2.png"));break;
        case 128:gui->B5->setPixmap(QPixmap(":/new/128v2.png"));break;
        case 256:gui->B5->setPixmap(QPixmap(":/new/256v2.png"));break;
        case 512:gui->B5->setPixmap(QPixmap(":/new/512v2.png"));break;
        case 1024:gui->B5->setPixmap(QPixmap(":/new/1024v2.png"));break;
        case 2048:gui->B5->setPixmap(QPixmap(":/new/2048v2.png"));break;

    }
    case 5:
    switch (box[i])
    {
        case 0:gui->B6->setPixmap(QPixmap(":/new/0.png"));break;
        case 2:gui->B6->setPixmap(QPixmap(":/new/2v2.png"));break;
        case 4:gui->B6->setPixmap(QPixmap(":/new/4v2.png"));break;
        case 8:gui->B6->setPixmap(QPixmap(":/new/8v2.png"));break;
        case 16:gui->B6->setPixmap(QPixmap(":/new/16v2.png"));break;
        case 32:gui->B6->setPixmap(QPixmap(":/new/32v2.png"));break;
        case 64:gui->B6->setPixmap(QPixmap(":/new/64v2.png"));break;
        case 128:gui->B6->setPixmap(QPixmap(":/new/128v2.png"));break;
        case 256:gui->B6->setPixmap(QPixmap(":/new/256v2.png"));break;
        case 512:gui->B6->setPixmap(QPixmap(":/new/512v2.png"));break;
        case 1024:gui->B6->setPixmap(QPixmap(":/new/1024v2.png"));break;
        case 2048:gui->B6->setPixmap(QPixmap(":/new/2048v2.png"));break;

    }
    case 6:
    switch (box[i])
    {
        case 0:gui->B7->setPixmap(QPixmap(":/new/0.png"));break;
        case 2:gui->B7->setPixmap(QPixmap(":/new/2v2.png"));break;
        case 4:gui->B7->setPixmap(QPixmap(":/new/4v2.png"));break;
        case 8:gui->B7->setPixmap(QPixmap(":/new/8v2.png"));break;
        case 16:gui->B7->setPixmap(QPixmap(":/new/16v2.png"));break;
        case 32:gui->B7->setPixmap(QPixmap(":/new/32v2.png"));break;
        case 64:gui->B7->setPixmap(QPixmap(":/new/64v2.png"));break;
        case 128:gui->B7->setPixmap(QPixmap(":/new/128v2.png"));break;
        case 256:gui->B7->setPixmap(QPixmap(":/new/256v2.png"));break;
        case 512:gui->B7->setPixmap(QPixmap(":/new/512v2.png"));break;
        case 1024:gui->B7->setPixmap(QPixmap(":/new/1024v2.png"));break;
        case 2048:gui->B7->setPixmap(QPixmap(":/new/2048v2.png"));break;

    }
    case 7:
    switch (box[i])
    {
        case 0:gui->B8->setPixmap(QPixmap(":/new/0.png"));break;
        case 2:gui->B8->setPixmap(QPixmap(":/new/2v2.png"));break;
        case 4:gui->B8->setPixmap(QPixmap(":/new/4v2.png"));break;
        case 8:gui->B8->setPixmap(QPixmap(":/new/8v2.png"));break;
        case 16:gui->B8->setPixmap(QPixmap(":/new/16v2.png"));break;
        case 32:gui->B8->setPixmap(QPixmap(":/new/32v2.png"));break;
        case 64:gui->B8->setPixmap(QPixmap(":/new/64v2.png"));break;
        case 128:gui->B8->setPixmap(QPixmap(":/new/128v2.png"));break;
        case 256:gui->B8->setPixmap(QPixmap(":/new/256v2.png"));break;
        case 512:gui->B8->setPixmap(QPixmap(":/new/512v2.png"));break;
        case 1024:gui->B8->setPixmap(QPixmap(":/new/1024v2.png"));break;
        case 2048:gui->B8->setPixmap(QPixmap(":/new/2048v2.png"));break;

    }
    case 8:
    switch (box[i])
    {
        case 0:gui->B9->setPixmap(QPixmap(":/new/0.png"));break;
        case 2:gui->B9->setPixmap(QPixmap(":/new/2v2.png"));break;
        case 4:gui->B9->setPixmap(QPixmap(":/new/4v2.png"));break;
        case 8:gui->B9->setPixmap(QPixmap(":/new/8v2.png"));break;
        case 16:gui->B9->setPixmap(QPixmap(":/new/16v2.png"));break;
        case 32:gui->B9->setPixmap(QPixmap(":/new/32v2.png"));break;
        case 64:gui->B9->setPixmap(QPixmap(":/new/64v2.png"));break;
        case 128:gui->B9->setPixmap(QPixmap(":/new/128v2.png"));break;
        case 256:gui->B9->setPixmap(QPixmap(":/new/256v2.png"));break;
        case 512:gui->B9->setPixmap(QPixmap(":/new/512v2.png"));break;
        case 1024:gui->B9->setPixmap(QPixmap(":/new/1024v2.png"));break;
        case 2048:gui->B9->setPixmap(QPixmap(":/new/2048v2.png"));break;

    }
    case 9:
    switch (box[i])
    {
        case 0:gui->B10->setPixmap(QPixmap(":/new/0.png"));break;
        case 2:gui->B10->setPixmap(QPixmap(":/new/2v2.png"));break;
        case 4:gui->B10->setPixmap(QPixmap(":/new/4v2.png"));break;
        case 8:gui->B10->setPixmap(QPixmap(":/new/8v2.png"));break;
        case 16:gui->B10->setPixmap(QPixmap(":/new/16v2.png"));break;
        case 32:gui->B10->setPixmap(QPixmap(":/new/32v2.png"));break;
        case 64:gui->B10->setPixmap(QPixmap(":/new/64v2.png"));break;
        case 128:gui->B10->setPixmap(QPixmap(":/new/128v2.png"));break;
        case 256:gui->B10->setPixmap(QPixmap(":/new/256v2.png"));break;
        case 512:gui->B10->setPixmap(QPixmap(":/new/512v2.png"));break;
        case 1024:gui->B10->setPixmap(QPixmap(":/new/1024v2.png"));break;
        case 2048:gui->B10->setPixmap(QPixmap(":/new/2048v2.png"));break;

    }
    case 10:
    switch (box[i])
    {
        case 0:gui->B11->setPixmap(QPixmap(":/new/0.png"));break;
        case 2:gui->B11->setPixmap(QPixmap(":/new/2v2.png"));break;
        case 4:gui->B11->setPixmap(QPixmap(":/new/4v2.png"));break;
        case 8:gui->B11->setPixmap(QPixmap(":/new/8v2.png"));break;
        case 16:gui->B11->setPixmap(QPixmap(":/new/16v2.png"));break;
        case 32:gui->B11->setPixmap(QPixmap(":/new/32v2.png"));break;
        case 64:gui->B11->setPixmap(QPixmap(":/new/64v2.png"));break;
        case 128:gui->B11->setPixmap(QPixmap(":/new/128v2.png"));break;
        case 256:gui->B11->setPixmap(QPixmap(":/new/256v2.png"));break;
        case 512:gui->B11->setPixmap(QPixmap(":/new/512v2.png"));break;
        case 1024:gui->B11->setPixmap(QPixmap(":/new/1024v2.png"));break;
        case 2048:gui->B11->setPixmap(QPixmap(":/new/2048v2.png"));break;

    }
    case 11:
    switch (box[i])
    {
        case 0:gui->B12->setPixmap(QPixmap(":/new/0.png"));break;
        case 2:gui->B12->setPixmap(QPixmap(":/new/2v2.png"));break;
        case 4:gui->B12->setPixmap(QPixmap(":/new/4v2.png"));break;
        case 8:gui->B12->setPixmap(QPixmap(":/new/8v2.png"));break;
        case 16:gui->B12->setPixmap(QPixmap(":/new/16v2.png"));break;
        case 32:gui->B12->setPixmap(QPixmap(":/new/32v2.png"));break;
        case 64:gui->B12->setPixmap(QPixmap(":/new/64v2.png"));break;
        case 128:gui->B12->setPixmap(QPixmap(":/new/128v2.png"));break;
        case 256:gui->B12->setPixmap(QPixmap(":/new/256v2.png"));break;
        case 512:gui->B12->setPixmap(QPixmap(":/new/512v2.png"));break;
        case 1024:gui->B12->setPixmap(QPixmap(":/new/1024v2.png"));break;
        case 2048:gui->B12->setPixmap(QPixmap(":/new/2048v2.png"));break;

    }
    case 12:
    switch (box[i])
    {
        case 0:gui->B13->setPixmap(QPixmap(":/new/0.png"));break;
        case 2:gui->B13->setPixmap(QPixmap(":/new/2v2.png"));break;
        case 4:gui->B13->setPixmap(QPixmap(":/new/4v2.png"));break;
        case 8:gui->B13->setPixmap(QPixmap(":/new/8v2.png"));break;
        case 16:gui->B13->setPixmap(QPixmap(":/new/16v2.png"));break;
        case 32:gui->B13->setPixmap(QPixmap(":/new/32v2.png"));break;
        case 64:gui->B13->setPixmap(QPixmap(":/new/64v2.png"));break;
        case 128:gui->B13->setPixmap(QPixmap(":/new/128v2.png"));break;
        case 256:gui->B13->setPixmap(QPixmap(":/new/256v2.png"));break;
        case 512:gui->B13->setPixmap(QPixmap(":/new/512v2.png"));break;
        case 1024:gui->B13->setPixmap(QPixmap(":/new/1024v2.png"));break;
        case 2048:gui->B13->setPixmap(QPixmap(":/new/2048v2.png"));break;

    }
    case 13:
    switch (box[i])
    {
        case 0:gui->B14->setPixmap(QPixmap(":/new/0.png"));break;
        case 2:gui->B14->setPixmap(QPixmap(":/new/2v2.png"));break;
        case 4:gui->B14->setPixmap(QPixmap(":/new/4v2.png"));break;
        case 8:gui->B14->setPixmap(QPixmap(":/new/8v2.png"));break;
        case 16:gui->B14->setPixmap(QPixmap(":/new/16v2.png"));break;
        case 32:gui->B14->setPixmap(QPixmap(":/new/32v2.png"));break;
        case 64:gui->B14->setPixmap(QPixmap(":/new/64v2.png"));break;
        case 128:gui->B14->setPixmap(QPixmap(":/new/128v2.png"));break;
        case 256:gui->B14->setPixmap(QPixmap(":/new/256v2.png"));break;
        case 512:gui->B14->setPixmap(QPixmap(":/new/512v2.png"));break;
        case 1024:gui->B14->setPixmap(QPixmap(":/new/1024v2.png"));break;
        case 2048:gui->B14->setPixmap(QPixmap(":/new/2048v2.png"));break;

    }
    case 14:
    switch (box[i])
    {
        case 0:gui->B15->setPixmap(QPixmap(":/new/0.png"));break;
        case 2:gui->B15->setPixmap(QPixmap(":/new/2v2.png"));break;
        case 4:gui->B15->setPixmap(QPixmap(":/new/4v2.png"));break;
        case 8:gui->B15->setPixmap(QPixmap(":/new/8v2.png"));break;
        case 16:gui->B15->setPixmap(QPixmap(":/new/16v2.png"));break;
        case 32:gui->B15->setPixmap(QPixmap(":/new/32v2.png"));break;
        case 64:gui->B15->setPixmap(QPixmap(":/new/64v2.png"));break;
        case 128:gui->B15->setPixmap(QPixmap(":/new/128v2.png"));break;
        case 256:gui->B15->setPixmap(QPixmap(":/new/256v2.png"));break;
        case 512:gui->B15->setPixmap(QPixmap(":/new/512v2.png"));break;
        case 1024:gui->B15->setPixmap(QPixmap(":/new/1024v2.png"));break;
        case 2048:gui->B15->setPixmap(QPixmap(":/new/2048v2.png"));break;

    }
    case 15:
    switch (box[i])
    {
        case 0:gui->B16->setPixmap(QPixmap(":/new/0.png"));break;
        case 2:gui->B16->setPixmap(QPixmap(":/new/2v2.png"));break;
        case 4:gui->B16->setPixmap(QPixmap(":/new/4v2.png"));break;
        case 8:gui->B16->setPixmap(QPixmap(":/new/8v2.png"));break;
        case 16:gui->B16->setPixmap(QPixmap(":/new/16v2.png"));break;
        case 32:gui->B16->setPixmap(QPixmap(":/new/32v2.png"));break;
        case 64:gui->B16->setPixmap(QPixmap(":/new/64v2.png"));break;
        case 128:gui->B16->setPixmap(QPixmap(":/new/128v2.png"));break;
        case 256:gui->B16->setPixmap(QPixmap(":/new/256v2.png"));break;
        case 512:gui->B16->setPixmap(QPixmap(":/new/512v2.png"));break;
        case 1024:gui->B16->setPixmap(QPixmap(":/new/1024v2.png"));break;
        case 2048:gui->B16->setPixmap(QPixmap(":/new/2048v2.png"));break;

    }
    }
    }
}
void widget::start()
{

     srand(time(0));

     int newblock_1=rand()%16;
     int newblock_2=rand()%16;
     while(newblock_1==newblock_2)
     {
         newblock_2=rand()%16;
     }
     box[newblock_1]=2;
     box[newblock_2]=2;     
}

void widget::up()
{
    if(round==0)
         gui->attact->hide();
    change=false;
    for(int b=0;b<16;b++)
    {
        last[b]=box[b];
    }
    cout<<endl;
    for(int i=0;i<4;i++)
        {
            int n=0;
            int m=0;
            for(int f=0;f<4;f++)
         {
            check[f]=0;
         }
            for(int k=0;k<4;k++)
            {
                if(box[4*k+i]!=0)
                {
                    check[n]=box[4*k+i];
                    box[4*k+i]=0;
                    n++;
                }
            }
            for(int t=0;t<3;t++)
            {
                if(check[t]==check[t+1])
                {
                    check[t]=check[t]*2;
                    point=point+check[t];
                    gui->point->setNum(point);
                    check[t+1]=0;
                }
            }
            for(int r=0;r<4;r++)
            {
                if(check[r]!=0)
                {
                    box[4*m+i]=check[r];
                    m++;
                }
            }

        }
    for(int w=0;w<16;w++)
    {
        if(box[w]==2048)
        {
            gui->win->show();
            break;
        }
    }

    for(int b=0;b<16;b++)
    {
        if(last[b]!=box[b])
        {
            change=true;            
            break;
        }
        else
            change=false;
     }
    if(change==true)
        generate();
    else
    {
        ge=false;
        for(int k=0;k<16;k++)
        {
            if(box[k]==0)
            {
                ge=true;
                break;
            }
        }
        if(ge==false)
         gui->lose->show();
    }
    paint();

}
void widget::down()
{
    if(round==0)
         gui->attact->hide();
    change=false;
    for(int b=0;b<16;b++)
    {
        last[b]=box[b];
    }
    for(int i=0;i<4;i++)
    {
            int n=0;
            int m=3;
            for(int f=0;f<4;f++)
         {
            check[f]=0;
         }
            for(int k=0;k<4;k++)
            {
                if(box[4*k+i]!=0)
                {
                    check[n]=box[4*k+i];
                    box[4*k+i]=0;
                    n++;
                }
            }
            for(int t=3;t>0;t--)
            {
                if(check[t]==check[t-1])
                {
                    check[t]=check[t]*2;
                    point=point+check[t];
                    gui->point->setNum(point);
                    check[t-1]=0;
                }
            }
            for(int r=3;r>=0;r--)
            {
                if(check[r]!=0)
                {
                    box[4*m+i]=check[r];
                    m--;
                }
            }
        }
    for(int w=0;w<16;w++)
    {
        if(box[w]==2048)
        {
            gui->win->show();
            break;
        }
    }
    for(int b=0;b<16;b++)
    {
        if(last[b]!=box[b])
        {
            change=true;
            break;
        }
        else
            change=false;
     }
    if(change==true)
        generate();
    else
    {
        ge=false;
        for(int k=0;k<16;k++)
        {
            if(box[k]==0)
            {
                ge=true;
                break;
            }
        }
        if(ge==false)
         gui->lose->show();
    }
    paint();


}
void widget::right()
{
    if(round==0)
         gui->attact->hide();
    change=false;
    for(int b=0;b<16;b++)
    {
        last[b]=box[b];
    }
    for(int i=0;i<4;i++)
       {
           int n=0;
           int m=3;
           for(int f=0;f<4;f++)
        {
           check[f]=0;
        }
           for(int t=0;t<4;t++)
           {
               if(box[4*i+t]!=0)
               {
                   check[n]=box[4*i+t];
                   box[4*i+t]=0;
                   n++;
               }
           }
           for(int c=3;c>0;c--)
           {
               if(check[c]==check[c-1])
               {
                   check[c]=check[c]*2;
                   point=point+check[c];
                   gui->point->setNum(point);
                   check[c-1]=0;
               }
           }
           for(int r=3;r>=0;r--)
           {
               if(check[r]!=0)
               {
                   box[4*i+m]=check[r];
                   m--;
               }
           }
       }
    for(int w=0;w<16;w++)
    {
        if(box[w]==2048)
        {
            gui->win->show();
            break;
        }
    }
    for(int b=0;b<16;b++)
    {
        if(last[b]!=box[b])
        {
            change=true;
          break;
         }
        else
            change=false;
    }
    if(change==true)
        generate();
    else
    {
        ge=false;
        for(int k=0;k<16;k++)
        {
            if(box[k]==0)
            {
                ge=true;
                break;
            }
        }
        if(ge==false)
         gui->lose->show();
    }
    paint();

}
void widget::left()
{
    if(round==0)
         gui->attact->hide();
    change=false;
    for(int b=0;b<16;b++)
    {
        last[b]=box[b];
    }
    for(int i=0;i<4;i++)
        {
            for(int f=0;f<4;f++)
         {
            check[f]=0;
         }
            int n=0;
            int m=0;
            for(int t=0;t<4;t++)
            {
                if(box[4*i+t]!=0)
                {
                    check[n]=box[4*i+t];
                    box[4*i+t]=0;
                    n++;
                }
            }
            for(int c=0;c<3;c++)
            {
                if(check[c]==check[c+1])
                {
                    check[c]=check[c]*2;
                    point=point+check[c];
                    gui->point->setNum(point);
                    check[c+1]=0;
                }
            }
            for(int r=0;r<4;r++)
            {
                if(check[r]!=0)
                {
                    box[4*i+m]=check[r];
                    m++;
                }
            }

        }
    for(int w=0;w<16;w++)
    {
        if(box[w]==2048)
        {
            gui->win->show();
            break;
        }
    }
    for(int b=0;b<16;b++)
    {
        if(last[b]!=box[b])
        {
            change=true;
             break;
        }

     }
    if(change==true)
        generate();
    else
    {
        ge=false;
        for(int k=0;k<16;k++)
        {
            if(box[k]==0)
            {
                ge=true;
                break;
            }
        }
        if(ge==false)
         gui->lose->show();
    }
        paint();

}
void widget::keyPressEvent(QKeyEvent* event)
{
    switch (event->key()) {
    case Qt::Key_Up:
    {
         up();
    }break;
    case Qt::Key_Down:
    {
        down();
    }break;
    case Qt::Key_Right:
    {

        right();
    }break;
    case Qt::Key_Left:
    {
        left();
    }break;
    }
}



void widget::on_pushButton_clicked()
{
    for(int y=0;y<16;y++)
    {
        box[y]=0;
    }
    point=0;
    gui->win->hide();
    gui->lose->hide();
    gui->point->setNum(0);
    gui->people->hide();
    max=0;
    gui->attact->hide();
     gui->monster->setPixmap(QPixmap(":/new/min.png"));
     gui->monster->show();
    start();
    paint();

}

void widget::on_start_clicked()
{
    gui->back->close();
    gui->start->close();
}
