/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f3xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f3xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
extern point;
extern minute;
 void On_First7segment(){
  	   	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,0);
  	   }
  	   void On_Second7segment(){
  	   	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,0);}
  	   void On_Third7segment(){
  	   	  	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,0);
  	   	  }

  	   void On_Forth7segment(){
  	   	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_10,0);
  	   }
  	   void Off_First7segment(){
   	   	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,1);
  	   	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,0);
  	   		   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,0);
  	   		   		  		  	    	  	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,0);
  	   		   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,0);
  	   		   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,0);
  	   		   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,0);
  	   		   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,0);
  	   }
  	   void Off_Second7segment(){
  	   	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,1);
  	   	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,0);
  	   		   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,0);
  	   		   		  		  	    	  	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,0);
  	   		   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,0);
  	   		   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,0);
  	   		   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,0);
  	   		   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,0);}
  	   void Off_Third7segment(){
  	   	  	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,1);
  	   	  	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,0);
  	   	  		   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,0);
  	   	  		   		  		  	    	  	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,0);
  	   	  		   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,0);
  	   	  		   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,0);
  	   	  		   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,0);
  	   	  		   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,0);
  	   	  }

  	   void Off_Forth7segment(){
  	   	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_10,1);

  	   	 HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,0);
  	   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,0);
  	   		  		  	    	  	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,0);
  	   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,0);
  	   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,0);
  	   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,0);
  	   		  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,0);
  	   }
  	  void Number (int number){
  	  	  if(number==0){
  	  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,1);
  	  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,1);
  	  	    	  	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,1);
  	  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,1);
  	  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,1);
  	  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,1);

  	  	  }

  	  	  if(number==1){
  	  		 HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,1);
  	  		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,1);

  	  	  }
  	  	  if(number==2){
  	  		 HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,1);
  	   		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,1);
  	  	  }
  	  	  if(number==3){
  	  		 HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,1);
  	  		  	    	  	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,1);
  	  	  }
  	  	  if(number==4){
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,1);
  	  		  	    	  	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,1);
  	   		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,1);
  	  	  }
  	  	  if(number==5){
  	  		 HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,1);
  	  		  	    	  	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,1);
  	  	  }
  	  	  if(number==6){
  	  		                  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,1);
  	  		  	    	  	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,1);
  	  	  }
  	  	  if(number==7){
  	  		 HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,1);
  	  		  	    	  	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,1);

  	  	  }
  	  	  if(number==8){
  	  		 HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,1);
  	  		  	    	  	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,1);
  	  	  }
  	  	  if(number==9){

  	  		 HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,1);
  	  		  	    	  	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,1);
  	   		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,1);
  	  	  }
  	    }
//for keypads;

int turn=0;

extern keypadjump;
extern pause;
extern start;
extern UARTSETTIME;


//final
extern menu;
extern menuposition;
extern menuchoice;
extern clearmenuchoice;
extern mode;
extern returnfromchosen;



extern settingoption;
extern health;
extern speed;
extern vol;
extern blocks;
extern direction;
  uint32_t last_enter_time=0;


//buzz
extern TIM_HandleTypeDef htim2;
TIM_HandleTypeDef *pwm_timers=&htim2;
uint32_t pwm_channels=TIM_CHANNEL_2;

//change this later
volatile uint16_t volume=0;

void PWM_starts(){
	  HAL_TIM_PWM_Start(pwm_timers,pwm_channels);

}

void PWM_Change_Tones(uint16_t pwm_freq,uint16_t volume){
	  TIM4->CCR2=10;
	  if(pwm_freq==0||pwm_freq>20000){


		  __HAL_TIM_SET_COMPARE(pwm_timers,pwm_channels,0);


	  }
	  else{
		  const uint32_t internal_Clock_freq=HAL_RCC_GetSysClockFreq();
		  const uint16_t prescaler=1+internal_Clock_freq/pwm_freq/60000;
		  const uint32_t timer_clock=internal_Clock_freq/ prescaler;
		  const uint32_t period_cycle=timer_clock/pwm_freq;
        const uint32_t pulse_width=volume*period_cycle/1000/2;

        pwm_timers->Instance->PSC=prescaler-1;
        pwm_timers->Instance->ARR=period_cycle-1;
        pwm_timers->Instance->EGR=TIM_EGR_UG;
__HAL_TIM_SET_COMPARE(pwm_timers,pwm_channels,pulse_width);


	  }

}


#define ARRAY_SIZE 10 // Change this to the desired size of your array
volatile uint16_t volumeArray[ARRAY_SIZE]; // Define an array of uint16_t

typedef struct
{
    uint16_t frequency;
    uint16_t duration;
} Tone;
const Tone *volatile melody_ptr;
volatile uint16_t melody_tone_count;
volatile uint16_t current_tone_number;
volatile uint32_t current_tone_end;
volatile uint32_t last_button_press;
#define ARRAY_LENGTH(arr)(sizeof(arr)/sizeof((arr)[0]))
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


const Tone pink_panther[] = {

	// 1 -> 2000 			\		-500 -> 750 (-4)	       \	2000 -> 1800 			(1)
	// 2 -> 1000    ---------\		-250 -> 375 (-8)   ---------\	1000 -> 900 			(2)
	// 4 -> 500     ---------/		-125 -> 187 (-16)  ---------/	500 -> 450, 750 -> 675 	(4), (-4)
	// 8 -> 250			    /		        			       /	250 -> 225, 375 -> 337 	(8), (-8)
	// 16 -> 125		   			 								125 -> 112, 187 -> 168 	(16), (-16)


		{REST, 900},
  {REST, 450},
  {REST, 225},
  {NOTE_DS4, 225},
  {NOTE_E4, 675},
  {REST, 225},
  {NOTE_FS4, 225},
  {NOTE_G4, 675},
  {REST, 225},
  {NOTE_DS4, 225},
  {NOTE_E4, 337},
  {NOTE_FS4, 225},
  {NOTE_G4, 337},
  {NOTE_C5, 225},
  {NOTE_B4, 337},
  {NOTE_B4, 225},
  {NOTE_G4, 337},
  {NOTE_B4, 225},
  {NOTE_AS4, 900},
  {NOTE_A4, 168},
  {NOTE_G4, 168},
  {NOTE_E4, 168},
  {NOTE_D4, 168},
  {NOTE_E4, 900},
  {REST, 450},
  {REST, 225},
  {NOTE_DS4, 450},



  {NOTE_E4, 675},
  {REST, 225},
  {NOTE_FS4, 225},
  {NOTE_G4, 675},
  {REST, 225},
  {NOTE_DS4, 225},
  {NOTE_E4, 337},
  {NOTE_FS4, 225},
  {NOTE_G4, 337},
  {NOTE_C5, 225},
  {NOTE_B4, 337},
  {NOTE_G4, 225},
  {NOTE_B4, 337},
  {NOTE_E5, 225},
  {NOTE_DS5, 1800},
  {NOTE_D5, 900},
  {REST, 450},
  {REST, 225},
  {NOTE_DS4, 225},
  {NOTE_E4, 750},
  {REST, 225},
  {NOTE_FS4, 225},
  {NOTE_G4, 750},
  {REST, 225},
  {NOTE_DS4, 225},
  {NOTE_E4, 337},
  {NOTE_FS4, 225},
  {NOTE_G4, 337},
  {NOTE_C5, 225},
  {NOTE_B4, 337},
  {NOTE_E4, 225},
  {NOTE_G4, 337},
  {NOTE_B4, 225},



  {NOTE_AS4, 900},
  {NOTE_A4, 168},
  {NOTE_G4, 168},
  {NOTE_E4, 168},
  {NOTE_D4, 168},
  {NOTE_E4, 675},
  {REST, 450},
  {REST, 450},
  {NOTE_E5, 337},
  {NOTE_D5, 225},
  {NOTE_B4, 337},
  {NOTE_A4, 225},
  {NOTE_G4, 337},
  {NOTE_E4, 337},
  {NOTE_AS4, 112},
  {NOTE_A4, 337},
  {NOTE_AS4, 112},
  {NOTE_A4, 337},
  {NOTE_AS4, 112},
  {NOTE_A4, 337},
  {NOTE_AS4, 112},
  {NOTE_A4, 337},
  {NOTE_G4, 168},
  {NOTE_E4, 168},
  {NOTE_D4, 168},
  {NOTE_E4, 112},
  {NOTE_E4, 112},
  {NOTE_E4, 900},
  {		 0,   0}

};
void Change_Melody(const Tone *melody,uint16_t tone_count){
	melody_ptr=melody;
	melody_tone_count=tone_count;
	current_tone_number=0;

}


int c=0;
//c=melody_tone_count
void Update_Melody(){

	if(pause!=1){

	if((HAL_GetTick()>current_tone_end)&&(current_tone_number<melody_tone_count)){

		const Tone active_tone=*(melody_ptr+current_tone_number);
		PWM_Change_Tones(active_tone.frequency,volume);
		current_tone_end=HAL_GetTick()+active_tone.duration;
		current_tone_number++;
c++;
	}
	if(c==ARRAY_LENGTH( pink_panther)){
		c=0;
			Change_Melody( pink_panther,ARRAY_LENGTH( pink_panther));

	}


	}
	else {

		PWM_Change_Tones(0,0);

	}




}
/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */
  if(start==0){
	  PWM_starts();
	  		Change_Melody( pink_panther,ARRAY_LENGTH( pink_panther));
  start=1;
  }
  Update_Melody();
  	  	  	int firstpoint=0;
  			int secondpoint=0;
  			secondpoint=point/10;
  			firstpoint=point%10;

  			Off_First7segment();
  			Off_Third7segment();
  			Off_Forth7segment();
  			Off_Second7segment();
  			On_First7segment();
  				if(secondpoint==0)Number(0);
  				if(secondpoint==1)Number(1);
  				if(secondpoint==2)Number(2);
  				if(secondpoint==3)Number(3);
  				if(secondpoint==4)Number(4);
  				if(secondpoint==5)Number(5);
  				if(secondpoint==6)Number(6);
  				if(secondpoint==7)Number(7);
  				if(secondpoint==8)Number(8);
  				if(secondpoint==9)Number(9);
for(int i=0;i<30;i++);
  				Off_First7segment();
  				Off_Second7segment();
  				Off_Third7segment();
  				Off_Forth7segment();
  				On_Second7segment();

  					if(firstpoint==0)Number(0);
  					if(firstpoint==1)Number(1);
  					if(firstpoint==2)Number(2);
  					if(firstpoint==3)Number(3);
  					if(firstpoint==4)Number(4);
  					if(firstpoint==5)Number(5);
  					if(firstpoint==6)Number(6);
  					if(firstpoint==7)Number(7);
  					if(firstpoint==8)Number(8);
  					if(firstpoint==9)Number(9);

  					for(int i=0;i<30;i++);

  		  	  	  	int firsttime=0;
  		  			int secondtime=0;
  		  			secondtime=minute/10;
  		  			firsttime=minute%10;



  		  						Off_First7segment();
  		  		  				Off_Second7segment();
  		  		  				Off_Third7segment();
  		  		  				Off_Forth7segment();
  		  		  				On_Third7segment();

  		  		  					if(secondtime==0)Number(0);
  		  		  					if(secondtime==1)Number(1);
  		  		  					if(secondtime==2)Number(2);
  		  		  					if(secondtime==3)Number(3);
  		  		  					if(secondtime==4)Number(4);
  		  		  					if(secondtime==5)Number(5);
  		  		  					if(secondtime==6)Number(6);
  		  		  					if(secondtime==7)Number(7);
  		  		  					if(secondtime==8)Number(8);
  		  		  					if(secondtime==9)Number(9);

  		  	  					for(int i=0;i<30;i++);


  		  						Off_First7segment();
  		  		  				Off_Second7segment();
  		  		  				Off_Third7segment();
  		  		  				Off_Forth7segment();
  		  		  				On_Forth7segment();

  		  		  					if(firsttime==0)Number(0);
  		  		  					if(firsttime==1)Number(1);
  		  		  					if(firsttime==2)Number(2);
  		  		  					if(firsttime==3)Number(3);
  		  		  					if(firsttime==4)Number(4);
  		  		  					if(firsttime==5)Number(5);
  		  		  					if(firsttime==6)Number(6);
  		  		  					if(firsttime==7)Number(7);
  		  		  					if(firsttime==8)Number(8);
  		  		  					if(firsttime==9)Number(9);
  	  		  	  					for(int i=0;i<30;i++);

  	  		  						Off_First7segment();
  	  		  		  				Off_Second7segment();
  	  		  		  				Off_Third7segment();
  	  		  		  				Off_Forth7segment();

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F3xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f3xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line0 interrupt.
  */
void EXTI0_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_IRQn 0 */

  /* USER CODE END EXTI0_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
  /* USER CODE BEGIN EXTI0_IRQn 1 */

    // Initialize all rows to low state
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);

    // Introduce a small delay for debounce (if necessary)
   // HAL_Delay(10);

    for (int turn = 0; turn < 4; turn++) {
      switch(turn) {
        case 0:

           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);

        	break;
        case 1:
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);

        	break;
        case 2:
          HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
          break;
        case 3:
          HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);
          break;
      }

      // Check if any button in the current row is pressed
      if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_0)) {
        switch(turn) {
          case 0:
          	menu=1;

            //HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_9);
            break;

          case 1:
        	  if(HAL_GetTick()-last_enter_time<200)
        	         	 		 return;

        	         	 		 last_enter_time=HAL_GetTick();

        	         		  if(menuposition==0)menuposition=1;
        	         		  else if(menuposition==1)menuposition=2;
        	         		  else if(menuposition==2)menuposition=3;
        	         		  else if(menuposition==3)menuposition=0;

break;
          case 2:
/*if (start==0&&UARTSETTIME==1){
	start=1;
	PWM_starts();
		Change_Melody( pink_panther,ARRAY_LENGTH( pink_panther));

}*/


                 //  HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_9);

        	  if(HAL_GetTick()-last_enter_time<200)
                	         	 		 return;

                	         	 		 last_enter_time=HAL_GetTick();

                	         		  if(menuposition==3)menuposition=2;
                	         		  else if(menuposition==2)menuposition=1;
                	         		  else if(menuposition==1)menuposition=0;
                	         		  else if(menuposition==0)menuposition=3;

        	  break;
          case 3:
        	  menuchoice=1;
        	  if(menuposition==0){
        		  volume=0;
        		  vol=0;
        	  }

        	/*  if (pause==0)pause=1;
        	  else pause=0;*/
        	  break;
        }
        // Add a delay or handle the button press accordingly
        break; // Exit the loop if a button press is detected
      }

      // Reset the row pin after checking
      switch(turn) {
        case 0:
          HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
          break;
        case 1:
          HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
          break;
        case 2:
          HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
          break;
        case 3:
          HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);
          break;
      }
    }

    // Ensure all rows are reset to high state after processing
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);

    // Wait for the button to be released (debouncing)
    while (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_0));

  /* USER CODE END EXTI0_IRQn 1 */
}

/**
  * @brief This function handles EXTI line1 interrupt.
  */
void EXTI1_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI1_IRQn 0 */

  /* USER CODE END EXTI1_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
  /* USER CODE BEGIN EXTI1_IRQn 1 */

  // Initialize all rows to low state
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);

     // Introduce a small delay for debounce (if necessary)
    // HAL_Delay(10);

     for (int turn = 0; turn < 4; turn++) {
       switch(turn) {
         case 0:
           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
           break;
         case 1:
           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
           break;
         case 2:
           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
           break;
         case 3:
           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);
           break;
       }

       // Check if any button in the current row is pressed
       if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_1)) {
         switch(turn) {
           case 0:
        	   if(HAL_GetTick()-last_enter_time<200)
        	                      	         	 		 return;

        	                      	         	 		 last_enter_time=HAL_GetTick();
        	   if(settingoption==0){
        		   health++;
        		   if(health==100)health=1;
        	   }
        	   else    if(settingoption==1){
        		   speed++;
        		   if(speed==11)speed=0;
        	   }
        	   else if(settingoption==2){
        		   if(vol==0){
        			   vol=1;
        			   volume=100;

        		   }
        		   else if(vol==1){
        			   vol=0;
        			   volume=0;

        		   }

        	   }
        	   else if(settingoption==3){
        		   blocks++;
        		   if(blocks==7)blocks=0;
        	   }
             HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_9);
             break;
           case 1:
        	   if(HAL_GetTick()-last_enter_time<200)
        	                      	         	 		 return;

        	                      	         	 		 last_enter_time=HAL_GetTick();
        	   if(menu==2){
        	                      	         		  if(settingoption==0)settingoption=1;
        	                      	         		  else if(settingoption==1)settingoption=2;
        	                       	         		  else if(settingoption==2)settingoption=3;
        	                       	         		  else if(settingoption==3)settingoption=0;

        	   }
             break;
           case 2:
        	   //choose mode
        	   if(HAL_GetTick()-last_enter_time<200)
        	                      	         	 		 return;

        	                      	         	 		 last_enter_time=HAL_GetTick();
        	   if(menu==2){
        	                      	         		  if(mode==0)mode=1;
        	                      	         		  else if(mode==1)mode=2;
        	                       	         		  else if(mode==2)mode=0;
        	   }
             HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_11);

             break;
           case 3:
        	   //back
        	   menuchoice=0;
        	   clearmenuchoice=0;
        	   menu=1;
        	   returnfromchosen=1;

             HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_12);
             break;
         }
         // Add a delay or handle the button press accordingly
         break; // Exit the loop if a button press is detected
       }

       // Reset the row pin after checking
       switch(turn) {
         case 0:
           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
           break;
         case 1:
           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
           break;
         case 2:
           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
           break;
         case 3:
           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);
           break;
       }
     }

     // Ensure all rows are reset to high state after processing
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);

     // Wait for the button to be released (debouncing)
     while (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_1));

  /* USER CODE END EXTI1_IRQn 1 */
}

/**
  * @brief This function handles EXTI line2 and Touch Sense controller.
  */
void EXTI2_TSC_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI2_TSC_IRQn 0 */

  /* USER CODE END EXTI2_TSC_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
  /* USER CODE BEGIN EXTI2_TSC_IRQn 1 */
  // Initialize all rows to low state
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);

     // Introduce a small delay for debounce (if necessary)
    // HAL_Delay(10);

     for (int turn = 0; turn < 4; turn++) {
       switch(turn) {
         case 0:
           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
           break;
         case 1:
           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
           break;
         case 2:
           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
           break;
         case 3:
           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);
           break;
       }

       // Check if any button in the current row is pressed
       if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_2)) {
         switch(turn) {
           case 0:
        	   if(HAL_GetTick()-last_enter_time<200)
        	                 	         	 		 return;
        	                 	         	 		 last_enter_time=HAL_GetTick();
//up
        	                 	         	 		 //1=up 2=down 3=left 4 =right
if(direction==3||direction==4)direction=1;
             HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_9);
             break;
           case 1:
        	   if(HAL_GetTick()-last_enter_time<200)
        	        	                 	         	 		 return;
        	        	                 	         	 		 last_enter_time=HAL_GetTick();
        	   //down
        	   if(direction==3||direction==4)direction=2;

             HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_10);
             break;
           case 2:
        	   if(HAL_GetTick()-last_enter_time<200)
        	        	                 	         	 		 return;
        	        	                 	         	 		 last_enter_time=HAL_GetTick();
        	   //left
        	   if(direction==1||direction==2)direction=3;

             HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_11);
             break;
           case 3:   if(HAL_GetTick()-last_enter_time<200)
    	 		 return;
    	 		 last_enter_time=HAL_GetTick();
        	   if(direction==1||direction==2)direction=4;

             HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_12);
             break;
         }
         // Add a delay or handle the button press accordingly
         break; // Exit the loop if a button press is detected
       }

       // Reset the row pin after checking
       switch(turn) {
         case 0:
           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
           break;
         case 1:
           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
           break;
         case 2:
           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
           break;
         case 3:
           HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);
           break;
       }
     }

     // Ensure all rows are reset to high state after processing
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);

     // Wait for the button to be released (debouncing)
     while (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_2));

  /* USER CODE END EXTI2_TSC_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
