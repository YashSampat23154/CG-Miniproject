#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

int main(){

	int gd=DETECT, gm;
	initgraph(&gd, &gm,"c:\\tc\\bgi");
	int x_min, x_max, y_cycle, y_man, shouldMove = 1, d = 0;

    setbkcolor(0);


    for(int i = 0; i<600; i+=3){

        x_min = 15+i, x_max = 185+i, y_cycle = 340, y_man = 300;


        // Rain Animation
        setcolor(9);

        for(int count=0;count<20;count++){
            int rx=rand()%639;
            int ry=rand()%428;
            // if(rx>=x_min && rx<=x_max){
            //     if(ry>=y_cycle){
            //         line(rx,ry,rx,ry);
            //         continue;
            //     }
            // }   
            
            line(rx-10,ry+10,rx,ry);
        }

        delay(11);



        // Cycle Animation
        setcolor(15);

        // Cycle - Body without Man
        line(50+150, 405, 100+150, 405);
        line(75+150, 375, 125+150, 375);
        line(50+150, 405, 75+150, 375);
        line(100+150, 405, 125+150, 375);
        line(150+150, 405, 100+150, 345);
        line(75+150, 375, 75+150, 370);
        line(70+150, 370, 80+150, 370);
        line(80+150, 345, 100+150, 345);

        // Cycle - Wheels
        circle(150+150,405,30);
        circle(50+150,405,30);

        // Road
        line(0, 436 ,getmaxx(), 436);


        // Stone on road
        rectangle(getmaxx(), 436, 650, 431);



        // Man Animation
        circle(i,y_man,20);                 //face
        line(i,y_man+20,i,y_man+40);        //neck
        line(i,y_man+40,i-30,y_man+70);     //left hand
        line(i,y_man+40,i+30,y_man+70);     //right hand
        line(i,y_man+40,i,y_man+80);        //body


         if(shouldMove)
        {
            if(d<20)
                d+=4;
            else
                shouldMove=0;
            line(i,y_man+80,i-d,y_man+130);
            line(i,y_man+80,i+d,y_man+130);
        }
        else
        {
            if(d>0)
                d-=4;
            else
                shouldMove=1;
            line(i,y_man+80,i-d,y_man+130);
            line(i,y_man+80,i+d,y_man+130);
        }
        
        if(i >= 250)
            break;


        delay(10);
        cleardevice();

     
    }


    cleardevice();


    for(int j = 0; j<400; j+=3){

         x_min = 15+j, x_max = 185+j, y_cycle = 340, y_man = 300;


        // Rain Animation
        setcolor(9);

        for(int count=0;count<20;count++){
        
            int rx=rand()%639;
            int ry=rand()%428;
        
            // if(rx>=x_min && rx<=x_max){
            //     if(ry>=y_cycle){
            //         line(rx,ry,rx,ry);
            //         continue;
            //     }
            // }   
            
            line(rx-10,ry+10,rx,ry);
        }

        delay(11);



        // Cycle Animation
        setcolor(15);

        // Cycle - Body with Man

        // Man
        circle(75+j+150,300,20);                // Head
        line(75+j+150, 320, 75+j+150, 370);     //Body
        line(75+j+150, 370, 100+j+150, 410);     //Legs

        // Cycle
        line(50+j+150, 405, 100+j+150, 405);
        line(75+j+150, 375, 125+j+150, 375);
        line(50+j+150, 405, 75+j+150, 375);
        line(100+j+150, 405, 125+j+150, 375);
        line(150+j+150, 405, 100+j+150, 345);
        line(75+j+150, 375, 75+j+150, 370);
        line(70+j+150, 370, 80+j+150, 370);
        line(80+j+150, 345, 100+j+150, 345);

        // Cycle - Wheels
        circle(150+j+150,405,30);
        circle(50+j+150,405,30);

        // Road
        line(0, 436 ,getmaxx(), 436);


        // Stone on road
        rectangle(getmaxx()-j, 436, 650-j, 431);


        delay(10);
        cleardevice();

     
    }



	getch();
	closegraph();
	return(0);
}