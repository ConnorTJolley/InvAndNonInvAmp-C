//Connor Jolley
//30.07.2017
//Inverted and Non-inverted amplifier voltage out calculator

#include <string.h>
#include <stdio.h>


int Resistor1 = 0;
int Resistor2 = 0;

int VoltageIn = 0;
int VoltageOut = 0;

int Choice = 0;

int x = 0;


main(void)
{
    while(x<1)
    {
       printf("1. Inverting Amp \n");
        printf("2. Non-inverting Amp \n");
        printf("Please enter what type of OP-amp you would like to calculate: ");
        scanf("%d",&Choice);

        if(Choice == 1)
        {
            printf("You have selected Inverting Amp! \n");
            InvertedAmpCalc();
            //Run Function to get inputs for Inverted Amp calc
        }
        else if(Choice == 2)
        {
            printf("You have selected Non-inverting Amp! \n");
            NonInvertAmpCalc();
            //Run Function to get inputs for Non-inverted Amp calc
        }
        else
        {
            printf("That was not a valid option! \n");
        }
    }
}

//Inverted amplifier calculator that calculates the voltage out based on -Vin * (Rf/Rg)
InvertedAmpCalc()
{

    int MinusVoltageIn = 0;
    double ResistorCalc = 0;

    printf("Please enter the number of the Voltage In: ");
    scanf(" %d",&VoltageIn);
    printf(" \n");
    printf("You have entered: %dv.", VoltageIn, " \n");
    printf(" \n");
    printf("Please entered the number of k Rg is: ");
    scanf(" %d", &Resistor1);
    printf("You have entered: %dk.", Resistor1, " \n");
    printf(" \n");
    printf("Please enter the number of k Rf is: ");
    scanf(" %d", &Resistor2);
    printf("You have entered: %dk.", Resistor2, " \n");
    printf(" \n");
    printf(" \n");

    MinusVoltageIn = ~VoltageIn + 1;

    printf("Voltage in is: %dv.", MinusVoltageIn);
    printf(" \n");

    ResistorCalc = Resistor2/Resistor1;
    ResistorCalc = (ResistorCalc*1000.0)/1000.0;
    printf("(R2 / R1) Is: %.6f", ResistorCalc);
    printf(" \n");
    VoltageOut = MinusVoltageIn * ResistorCalc;
    printf("Vo = -Vin * R2 / R1 Is: %dv", VoltageOut);

    printf(" \n");
    printf(" \n");
    main();
}

//Non inverted amplifier calculator that calculates the voltage out based on Vin(1+Rf/Rg)
NonInvertAmpCalc()
{
    double ResistorCalc1 = 0;
    int VoltageIn1 = 0;

    printf("Please enter the number of the Voltage In: ");
    scanf(" %d",&VoltageIn1);
    printf(" \n");
    printf("You have entered: %dv.", VoltageIn1, " \n");
    printf(" \n");
    printf("Please entered the number of k Rf is: ");
    scanf(" %d", &Resistor1);
    printf("You have entered: %dk.", Resistor1, " \n");
    printf(" \n");
    printf("Please enter the number of k Rg is: ");
    scanf(" %d", &Resistor2);
    printf("You have entered: %dk.", Resistor2, " \n");
    printf(" \n");
    printf(" \n");

    ResistorCalc1 = 1+Resistor1/Resistor2;
    printf("1 + R1/R2 = %.6f", ResistorCalc1);
    printf(" \n");
    VoltageOut = VoltageIn1 * ResistorCalc1;
    printf("Vin * 1 + R1/R2 = %dv", VoltageOut);
    printf(" \n");
    printf(" \n");
    main();
}
