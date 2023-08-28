#include <stdio.h>
#include <string.h>  
#include <stdlib.h>


void manufacturers(int toyota, int chevrolet, int nissan, int bmw, int volkswagon)
{
if(toyota == 1)
{
    printf("1.) Toyota \t");
} 
if (chevrolet == 1)
{
    printf("2.) Chevrolet \t");
}
if (nissan == 1)
{
    printf("3.) Nissan \t");

}
if (bmw == 1)
{
    printf("4.) BMW \t");

} 
if (volkswagon == 1)
{
    printf("5.) volkswagon \n");
}

}
//calculates monthly payment.
float monthly_payment(float price, int downpayment, float apr)
{
float principal = price - downpayment;
return ((principal + (principal*apr*5))/ (5*12));

}

float interest(int salary)
{
    //interest rate is determined by salary.
    if(salary > 125000)
    {
        return .0479;

    }  else if (salary > 80000)
    {
        return .0655;

    } else if (salary > 45000)
    {
        return .0949;

    } else if (salary < 45000)
    {
        return .1328;
    }
}



//Check what car vaules can be afforded.
float affordablility(int salary)
{
//15% of monthly gross salary.
return (salary / 12) * .15;

}

//Car dealership program.
int main(int argc, char * argv[])
{
char stringnumber[10];
int salary;
int downpayment;
float affordable;
float apr;
float carpayment;
int affordable_cars[55];
int Toyota;
int Chevrolet;
int BMW;
int Nissan;
int Volkwagon;
int manufacture_choice;
int model_choice;
int count = 0;
int final_selections [11];

//creating struct for the cars.
struct car
{
    char manufacturer[20];
    char make[20];
    char model[25];
    int price;
};

struct car carlot[50] = {
{"Toyota","Toyota","Corolla",21550},
{"Toyota","Toyota","Camry",25945},  
{"Toyota","Toyota","Avalon",36825}, 
{"Toyota","Toyota","Mirai",49500}, 
{"Toyota","Toyota","Sequoia",58300},  
{"Toyota","Toyota","Tacoma",27250},  
{"Toyota","Toyota","Tundra",36965},  
{"Toyota","Lexus","IS",40585},  
{"Toyota","Lexus","ES",42490},  
{"Toyota","Lexus","GX",57575},

{"Chevrolet","Chevy","Trailblazer",22100},  
{"Chevrolet","Chevy","Camaro",26100},  
{"Chevrolet","Chevy","Equinox",26600},  
{"Chevrolet","Chevy","Traverse",34520},  
{"Chevrolet","Chevy","Tahoe",54200},  
{"Chevrolet","Chevy","Suburban",56900},  
{"Chevrolet","Chevy","Corvette",64500},  
{"Chevrolet","Chevy","Spark",13600},  
{"Chevrolet","Chevy","Trax",21700},  
{"Chevrolet","Chevy","Malibu",23400},  

{"Nissan","Nissan","Versa",18990},  
{"Nissan","Nissan","Sentra",22700},  
{"Nissan","Nissan","Altima",35385},  
{"Nissan","Nissan","Maxima",43300},  
{"Nissan","Nissan","Pathfinder",50660},  
{"Nissan","Nissan","Rogue",38640},  
{"Nissan","Nissan","Murano",46910},  
{"Nissan","Infiniti","Q50",42650}, 
{"Nissan","Infiniti","QX55",49150},  
{"Nissan","Infiniti","QX80",72700},  

{"BMW","BMW","2 Series Coupe",38050},  
{"BMW","BMW","3 Series Sedan",48220}, 
{"BMW","BMW","4 Series Convertible",59320},  
{"BMW","BMW","5 Series Sedan",55175},  
{"BMW","BMW","7 Series Sedan",93400},  
{"BMW","BMW","X1",39700},
{"BMW","BMW","X3",46050}, 
{"BMW","BMW","X4",54050},
{"BMW","BMW","X5",75400},
{"BMW","BMW","X7",77850}, 

{"Volkswagen","VW","Jetta",18995},
{"Volkswagen","VW","Passat",23995},
{"Volkswagen","VW","Arteon",36995},
{"Volkswagen","Audi","Q5",43500},
{"Volkswagen","Audi","Q3",38700},
{"Volkswagen","Audi","S6",72700},
{"Volkswagen","Audi","A6",55900},
{"Volkswagen","Porsche","Panamera",132760},
{"Volkswagen","Porsche","Macan",69480},
{"Volkswagen","Porsche","Cayenne",92960} 
};


//read from terminal salary.
strcpy(stringnumber, argv[1]);
salary = strtoq(stringnumber,NULL,10);

//getting down payment.
printf("Enter down payment: ");
scanf("%d",&downpayment);

//Check what payment can be afforded.
affordable = affordablility(salary);
//printf("The maximum payment you qualified for is: $%.2f\n", affordable);

//find out qualifed interest rate
apr = interest(salary);

 //collect the index of cars that can be afforded.
 for(int i = 0; i < 50; i++ )
 {
    carpayment = monthly_payment(carlot[i].price, downpayment, apr);

    if(affordable > carpayment)
    {
        affordable_cars[i] = i;
    }


 }
//checking what manufacturers are affordable. 
 for(int i = 0; i < 50; i ++ )
 {
    if(affordable_cars[i] == i && i <= 9 )
    {
        Toyota = 1;
    } else if((affordable_cars[i] == i  && i <= 19  ))
    {
        Chevrolet = 1;
    } else if((affordable_cars[i] == i &&  i <= 29 ))
    {
        Nissan = 1;
    } else if((affordable_cars[i] == i && i <= 39 ))
    {
        BMW = 1;
    } else if((affordable_cars[i] == i && i <= 49 ))
    {
        Volkwagon = 1;
    }


 }
 //displaying affordable manufacturers.
printf("Available Manufacturers: \n");


manufacturers(Toyota, Chevrolet, Nissan, BMW, Volkwagon);
//reading choice of manufacturer.
printf("Select manufacturer: ");
scanf("%d",&manufacture_choice);

printf("Available make/model: \n");

//displaying available makes and models.
if(manufacture_choice == 1)
{
    //printing all Toyota cars that can be afforded.
    for(int i = 0; i <= 9; i ++)
    {
        if(affordable_cars[i] == i){
            
            count++;
            //store index of cars that were displayed.
            final_selections[count] = i;

        printf("%d.) %s %s- $%d \n",count, carlot[affordable_cars[i]].make,carlot[affordable_cars[i]].model,carlot[affordable_cars[i]].price);

        }
    }
} else if(manufacture_choice == 2) 
{
    //printing all Chevrolet cars that can be afforded.
    for(int i = 10; i <= 19; i ++)
    {
        if(affordable_cars[i] == i){

            count++;
            //store index of cars that were displayed.
            final_selections[count] = i;
        printf("%d.) %s %s- $%d \n",count, carlot[i].make,carlot[i].model,carlot[i].price);

        }
    }
} else if(manufacture_choice == 3)
{
    //printing all Nissan cars that can be afforded.
 for(int i = 20; i <= 29; i ++)
    {
        if(affordable_cars[i] == i ){
              
            count++;
            //store index of cars that were displayed.
            final_selections[count] = i;
        printf("%d.) %s %s- $%d \n",count, carlot[i].make,carlot[i].model,carlot[i].price);

        }
    }   
} else if (manufacture_choice == 4 )
{
    //printing all BMW cars that can be afforded.
  for(int i = 30; i <= 39; i ++)
    {
        if(affordable_cars[i] == i){
            
            count++; 
            //store index of cars that were displayed.
            final_selections[count] = i;
        printf("%d.) %s %s- $%d \n",count, carlot[i].make,carlot[i].model,carlot[i].price);

        }
    }
} else if( manufacture_choice == 5)
{
    //printing all Volkwagon cars that can be afforded.
 for(int i = 40; i <= 49; i ++)
    {
        if(affordable_cars[i] == i){
            
            count++;
            //store index of cars that were displayed.
            final_selections[count] = i;

        printf("%d.) %s %s- $%d \n",count, carlot[i].make,carlot[i].model,carlot[i].price);

        }
    }
       

}
//Scanning the index of the selected model.
printf("Please select make/model: ");
scanf("%d",&model_choice);
//calculating monthly payment for car
carpayment = monthly_payment(carlot[final_selections[model_choice]].price, downpayment, apr);
if(carpayment < 0 ){
    //if there is no monthly payment needed.
    printf("You selected %s %s. You have no monthly payment.\n", carlot[final_selections[model_choice]].make,carlot[final_selections[model_choice]].model);

} else{
    //if car needs to be financed.
    printf("You selected %s %s. your monthly payment is $%.2f.\n", carlot[final_selections[model_choice]].make,carlot[final_selections[model_choice]].model,carpayment);
}
return (0);
}
