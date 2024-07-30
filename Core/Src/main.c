/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "LiquidCrystal.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

RTC_HandleTypeDef hrtc;

SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart3;

PCD_HandleTypeDef hpcd_USB_FS;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_SPI1_Init(void);
static void MX_USB_PCD_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_RTC_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


 int keypadjump=0;
 int pause=0;
 int start=0;

 RTC_TimeTypeDef sTime;
 RTC_DateTypeDef sDate;

 int UARTSETTIME=0;
  char rxBuffer[3]; // Buffer to store received data (8 characters + null terminator)
  //store input timer
char time[6];

//convert to rtc
uint8_t hourString[3];  // Buffer to hold the hour string for transmission
uint8_t minString[3];  // Buffer to hold the hour string for transmission
uint8_t secString[3];  // Buffer to hold the hour string for transmission

int initiate=0;



int mode=0;
int menu=0;
int menuposition=-1;
//for accepting menu option binary
int  menuchoice=0;


int clearmenuchoice=0;

int settingoption=0;
int health=1;
int speed=9;
int vol=1;
int blocks=4;

int returnfromchosen=0;
int end;

int mysterytimecount=0;
int xmystery=0;
int ymystery=0;
//heart=3
//4=mystery
//2=block
//1=apple

//6=body
//5=head
//-1=nothing


int grid[4][20];

//1=up;
//2=dwn;
//3=left;
//4=right;
int direction=4;
int snakelenght=1;

int currenthealth=2;
int currentapples=3;
int point=0;
//head to tale ([][])-->prioprity
int minute=0;

int finishgame=0;
typedef unsigned char byte;
byte heart[8] = {
  0x00,
  0x00,
  0x0A,
  0x15,
  0x11,
  0x0A,
  0x04,
  0x00
};
byte apple[8] = {
  0x00,
  0x06,
  0x04,
  0x0E,
  0x0E,
  0x0E,
  0x00,
  0x00
};
byte block[] = {
  0x00,
  0x1F,
  0x04,
  0x04,
  0x04,
  0x04,
  0x1F,
  0x00
};
byte luckybox[] = {
  0x00,
  0x0E,
  0x0A,
  0x06,
  0x04,
  0x00,
  0x04,
  0x00
};
byte menucursor[] = {
  0x00,
  0x18,
  0x1C,
  0x1E,
  0x1C,
  0x18,
  0x00,
  0x00
};
byte snake[] = {
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F
};
byte headsnake[] = {
  0x1F,
  0x1F,
  0x1F,
  0x19,
  0x19,
  0x1F,
  0x1F,
  0x1F
};

struct Segment{
	int x;
	int y;
	struct Segment *next;

};
enum Direction {UP, DOWN, LEFT, RIGHT};
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

 	//empty field

	enum Direction currentDir = RIGHT;

	for(int i=0;i<4;i++){
		for(int j=0;j<20;j++){

			  grid[i][j]=-1;

		}
	}

	// Initialize snake
	struct Segment* segment = malloc(sizeof(struct Segment));
	struct Segment* tail = malloc(sizeof(struct Segment));

	segment->x = 0;
	segment->y = 1;
	segment->next = tail;


	tail->x=0;
	tail->y=0;
	tail->next=NULL;

grid[0][0]=6;
grid[0][1]=5;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_SPI1_Init();
  MX_USB_PCD_Init();
  MX_USART3_UART_Init();
  MX_RTC_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */



  LiquidCrystal(GPIOD,GPIO_PIN_8,GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11,GPIO_PIN_12,GPIO_PIN_13, GPIO_PIN_14);
  begin(20,4);


  RTC_TimeTypeDef mytime;
  int number=0;

  TIM_HandleTypeDef *pwm_timers=&htim2;
  uint32_t pwm_channels=TIM_CHANNEL_2;
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
  	  		 			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_0,1);
  	  		  	    		  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_1,1);
  	  		  	    	  	  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,1);

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
  
 	
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
sTime.Hours=0;
sTime.Minutes=0;
sTime.Seconds=0;
sDate.Date=2;
sDate.Month=9;
sDate.Year=24;

HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);



// Function to print the grid
/*void printGrid(int grid[4][20]) {
for (int i = 0; i < 4; i++) {
for (int j = 0; j < 20; j++) {
	if (grid[i][j]==5){
		setCursor(j, i);
		 write(5);

	}
	if (grid[i][j]==6){
			setCursor(j, i);
			 write(6);

		}
	if (grid[i][j]==-1){
				setCursor(j, i);
print(" ");
			}
}

}}*/
// Function to move the snake
//mode1
void randomapple(){

	int rowmin=0;
	int rowmax=3;
	int colmin=0;
	int colmax=19;
	//random apple
	for(int i=0;i<1;i++){
		int rowrandom=(rand()%(rowmax-rowmin+1)+rowmin);
int colrandom=(rand()%(colmax-colmin+1)+colmin);
if(grid[rowrandom][colrandom]==-1){
	setCursor(colrandom, rowrandom);
	write(1);
	grid[rowrandom][colrandom]=1;
}
else i--;


}

}
void randommys(){

	int rowmin=0;
	int rowmax=3;
	int colmin=0;
	int colmax=19;
	//random apple
	for(int i=0;i<1;i++){
		int rowrandom=(rand()%(rowmax-rowmin+1)+rowmin);
int colrandom=(rand()%(colmax-colmin+1)+colmin);
if(grid[rowrandom][colrandom]==-1){
	setCursor(colrandom, rowrandom);
	write(3);
	grid[rowrandom][colrandom]=4;
	xmystery=rowrandom;
	ymystery=colrandom;
mysterytimecount++;
}
else i--;


}
}
void randomhealth(){

	int rowmin=0;
	int rowmax=3;
	int colmin=0;
	int colmax=19;
	//randomheart
	for(int i=0;i<1;i++){
		int rowrandom=(rand()%(rowmax-rowmin+1)+rowmin);
int colrandom=(rand()%(colmax-colmin+1)+colmin);
if(grid[rowrandom][colrandom]==-1){
	setCursor(colrandom, rowrandom);
	write(0);
	grid[rowrandom][colrandom]=3;
}
else i--;


}

}
void moveSnake(struct Segment* head, enum Direction dir,   int grid[4]
[20]) {

// Determine the new head position
int newX = head->x;
int newY = head->y;
switch (dir) {
case UP: newX--; break;
case DOWN: newX++; break;
case LEFT: newY--; break;
case RIGHT: newY++; break;
}
// Wrap around the grid
if (newX < 0) newX = 4 - 1;
if (newX >= 4) newX = 0;
if (newY < 0) newY = 20 - 1;
if (newY >= 20) newY = 0;
struct Segment* tails = head;

mysterytimecount++;
if(mysterytimecount>5){
	mysterytimecount=0;
	grid[xmystery][ymystery]=-1;
	setCursor(ymystery, xmystery);
	print(" ");
	randommys();
}
// Check for apple

int delete=0;
//apple
if (grid[newX][newY]==1) {
	PWM_Change_Tones(500, 100);
	point++;
	delete=1;
	grid[newX][newY]=-1;
	setCursor(newY, newX);
	print(" ");

// Add new head segment


	struct Segment* newHead = malloc(sizeof(struct Segment));
	newHead->x = newX;

	newHead->y = newY;


	newHead->next = head;

	segment = newHead;
	currentapples--;
	if(currentapples==0)
	{

		currentapples=1;
		randomapple();
	}

	PWM_Change_Tones(0, 0);
}
//health
if (grid[newX][newY]==3) {

	PWM_Change_Tones(650, 100);

	grid[newX][newY]=-1;

	if(health<99)
	health++;
	currenthealth--;
	if(currenthealth==0)
	{
		currenthealth=1;
		randomhealth();
	}
	PWM_Change_Tones(650, 100);

}
//mystery
if (grid[newX][newY]==4) {
	PWM_Change_Tones(400, 100);

	grid[newX][newY]=-1;

	int random=(rand()%(3-1+1)+1);
//0->>+2point
	//1->+2health
//2 -speed
	if(random==0){
		if(point<99)point=point+2;;

	}
	if(random==1){
		if(health<99)health=health+2;
	}
	if(random==2){
		if(speed>=2)speed--;
	}
	PWM_Change_Tones(0, 0);

}
//block
if (grid[newX][newY]==2) {
	health--;

	PWM_Change_Tones(700, 100);
HAL_Delay(10);
if(currentDir==RIGHT)
{
currentDir=DOWN;
direction=2;
}else if(currentDir==DOWN){
currentDir=LEFT;
direction=3;
}
else if(currentDir==LEFT){
	direction=1;
	currentDir=UP;}
else if(currentDir==UP){
	currentDir=RIGHT;
direction=4;}
PWM_Change_Tones(0, 0);

return;

}
//barkhord be badan
if(grid[newX][newY]==6){
	health--;

	if(health==0)
	{
		//clear();
	//	HAL_Delay(5000);
	}
}


// Move the snake by removing the tail and adding a new head
if(delete==0){
tails = head;
while ( tails->next->next != NULL) {

tails = tails->next;
}


grid[tails->next->x][tails->next->y] = -1;

setCursor(tails->next->y, tails->next->x);
print(" ");
free(tails->next);
tails->next = NULL;

}delete=0;

struct Segment* newHead = malloc(sizeof(struct Segment));
newHead->x = newX;
newHead->y = newY;

newHead->next = head;
segment = newHead;


// Update grid with snake position

struct Segment* segments = segment;

if(  segments){

	grid[segments->x][segments->y] = 5;
setCursor(segments->y, segments->x);
write(5);
HAL_Delay(100);

}
	segments = segments->next;




while (segments != NULL) {
grid[segments->x][segments->y] = 6;
setCursor(segments->y, segments->x);

write(6);
segments = segments->next;






}
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


		HAL_Delay(1);
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

}



void moveSnake2(struct Segment* head, enum Direction dir,   int grid[4]
[20]) {

// Determine the new head position
int newX = head->x;
int newY = head->y;
switch (dir) {
case UP: newX--; break;
case DOWN: newX++; break;
case LEFT: newY--; break;
case RIGHT: newY++; break;
}
// Wrap around the grid
if (newX < 0){ newX = 4 - 1;health--;currentDir=RIGHT;
direction=4;}
if (newX >= 4) {newX = 0;health--;currentDir=LEFT;
direction=3;}
if (newY < 0) {newY = 20 - 1;health--;	direction=1;
currentDir=UP;}
if (newY >= 20){ newY = 0;health--;currentDir=DOWN;
direction=2;}
struct Segment* tails = head;

// Check for apple
mysterytimecount++;
if(mysterytimecount>5){
	mysterytimecount=0;
	grid[xmystery][ymystery]=-1;
	setCursor(ymystery, xmystery);
	print(" ");
	randommys();
}
int delete=0;
//apple
if (grid[newX][newY]==1) {
	PWM_Change_Tones(500, 100);

	point++;
	delete=1;
	grid[newX][newY]=-1;
	setCursor(newY, newX);
	print(" ");

// Add new head segment


	struct Segment* newHead = malloc(sizeof(struct Segment));
	newHead->x = newX;

	newHead->y = newY;


	newHead->next = head;

	segment = newHead;
	currentapples--;
	if(currentapples==0)
	{
		currentapples=1;
		randomapple();
	}
	PWM_Change_Tones(0, 0);

}
//health
if (grid[newX][newY]==3) {
	PWM_Change_Tones(650, 100);

	grid[newX][newY]=-1;

	if(health<99)
	health++;
	currenthealth--;
	if(currenthealth==0)
	{
		currenthealth=1;
		randomhealth();
	}
	PWM_Change_Tones(650, 100);

}
//mystery
if (grid[newX][newY]==4) {
	PWM_Change_Tones(400, 100);

	grid[newX][newY]=-1;
	int random=(rand()%(3-1+1)+1);
//0->>+2point
	//1->+2health
//2 -speed
	if(random==0){
		if(point<99)point=point+2;;

	}
	if(random==1){
		if(health<99)health=health+2;
	}
	if(random==2){
		if(speed>=2)speed--;
	}
	PWM_Change_Tones(0, 0);


}
//block
if (grid[newX][newY]==2) {
	health--;
	PWM_Change_Tones(700, 100);
	HAL_Delay(10);

if(currentDir==RIGHT)
{
currentDir=DOWN;
direction=2;
}else if(currentDir==DOWN){
currentDir=LEFT;
direction=3;
}
else if(currentDir==LEFT){
	direction=1;
	currentDir=UP;}
else if(currentDir==UP){
	currentDir=RIGHT;
direction=4;}
PWM_Change_Tones(0, 0);

return;
}
//barkhord be badan
if(grid[newX][newY]==6){
	health--;

	if(health==0)
	{
		//clear();
	//	HAL_Delay(5000);
	}
}


// Move the snake by removing the tail and adding a new head
if(delete==0){
tails = head;
while ( tails->next->next != NULL) {

tails = tails->next;
}


grid[tails->next->x][tails->next->y] = -1;

setCursor(tails->next->y, tails->next->x);
print(" ");
free(tails->next);
tails->next = NULL;

}delete=0;

struct Segment* newHead = malloc(sizeof(struct Segment));
newHead->x = newX;
newHead->y = newY;

newHead->next = head;
segment = newHead;


// Update grid with snake position

struct Segment* segments = segment;

if(  segments){

	grid[segments->x][segments->y] = 5;
setCursor(segments->y, segments->x);
write(5);
HAL_Delay(100);

}
	segments = segments->next;




while (segments != NULL) {
grid[segments->x][segments->y] = 6;
setCursor(segments->y, segments->x);

write(6);
segments = segments->next;






}
}
void moveSnake3(struct Segment* head, enum Direction dir,   int grid[4]
[20]) {

// Determine the new head position
int newX = head->x;
int newY = head->y;
switch (dir) {
case UP: newX--; break;
case DOWN: newX++; break;
case LEFT: newY--; break;
case RIGHT: newY++; break;
}
// Wrap around the grid
if (newX < 0) newX = 4 - 1;
if (newX >= 4) newX = 0;
if (newY < 0) newY = 20 - 1;
if (newY >= 20) newY = 0;
struct Segment* tails = head;


// Check for apple

int delete=0;
mysterytimecount++;
if(mysterytimecount>5){
	mysterytimecount=0;
	grid[xmystery][ymystery]=-1;
	setCursor(ymystery, xmystery);
	print(" ");
	randommys();
}
//apple
if (grid[newX][newY]==1) {
	PWM_Change_Tones(500, 100);

	point++;
	delete=1;
	grid[newX][newY]=-1;
	setCursor(newY, newX);
	print(" ");

// Add new head segment


	struct Segment* newHead = malloc(sizeof(struct Segment));
	newHead->x = newX;

	newHead->y = newY;


	newHead->next = head;

	segment = newHead;

	currentapples--;
if(currentapples==0)
{
	currentapples=1;
	randomapple();
}
PWM_Change_Tones(0, 0);

}
//health
if (grid[newX][newY]==3) {
	PWM_Change_Tones(650, 100);

	grid[newX][newY]=-1;

	if(health<99)
	health++;
	currenthealth--;
if(currenthealth==0)
{
	currenthealth=1;
	randomhealth();
}
PWM_Change_Tones(0, 0);

}
//mystery
if (grid[newX][newY]==4)
	PWM_Change_Tones(400, 100);
{
	grid[newX][newY]=-1;
	int random=(rand()%(3-1+1)+1);
//0->>+2point
	//1->+2health
//2 -speed
	if(random==0){
		if(point<99)point=point+2;;

	}
	if(random==1){
		if(health<99)health=health+2;
	}
	if(random==2){
		if(speed>=2)speed--;
	}
	PWM_Change_Tones(0, 0);

}
//block
if (grid[newX][newY]==2) {
	health--;

	PWM_Change_Tones(700, 100);
	HAL_Delay(10);

if(currentDir==RIGHT)
{
currentDir=DOWN;
direction=2;
}else if(currentDir==DOWN){
currentDir=LEFT;
direction=3;
}
else if(currentDir==LEFT){
	direction=1;
	currentDir=UP;}
else if(currentDir==UP){
	currentDir=RIGHT;
direction=4;}
PWM_Change_Tones(0, 0);

return;
}
//barkhord be badan
if(grid[newX][newY]==6){
	health--;

	if(health==0)
	{
		//clear();
	//	HAL_Delay(5000);
	}
}


// Move the snake by removing the tail and adding a new head
if(delete==0){
tails = head;
while ( tails->next->next != NULL) {

tails = tails->next;
}


grid[tails->next->x][tails->next->y] = -1;

setCursor(tails->next->y, tails->next->x);
print(" ");
free(tails->next);
tails->next = NULL;

}delete=0;

struct Segment* newHead = malloc(sizeof(struct Segment));
newHead->x = newX;
newHead->y = newY;

newHead->next = head;
segment = newHead;


// Update grid with snake position

struct Segment* segments = segment;

if(  segments){

	grid[segments->x][segments->y] = 5;
setCursor(segments->y, segments->x);
write(5);
HAL_Delay(100);

}
	segments = segments->next;




while (segments != NULL) {
grid[segments->x][segments->y] = 6;
setCursor(segments->y, segments->x);

write(6);
segments = segments->next;






}
}

void initialize(){

	int rowmin=0;
	int rowmax=3;
	int colmin=0;
	int colmax=19;
	srand(HAL_GetTick());
	//random block
	for(int i=0;i<blocks;i++){
		int rowrandom=(rand()%(rowmax-rowmin+1)+rowmin);
int colrandom=(rand()%(colmax-colmin+1)+colmin);
if(grid[rowrandom][colrandom]==-1){
	setCursor(colrandom, rowrandom);
	write(2);
	grid[rowrandom][colrandom]=2;
}
else i--;


	}

	//random heart
	for(int i=0;i<2;i++){
		int rowrandom=(rand()%(rowmax-rowmin+1)+rowmin);
int colrandom=(rand()%(colmax-colmin+1)+colmin);
if(grid[rowrandom][colrandom]==-1){
	setCursor(colrandom, rowrandom);
	write(0);
	grid[rowrandom][colrandom]=3;
}
else i--;


}

	//random apple
	for(int i=0;i<3;i++){
		int rowrandom=(rand()%(rowmax-rowmin+1)+rowmin);
int colrandom=(rand()%(colmax-colmin+1)+colmin);
if(grid[rowrandom][colrandom]==-1){
	setCursor(colrandom, rowrandom);
	write(1);
	grid[rowrandom][colrandom]=1;
}
else i--;


}
//a
randommys();
}
int finishuart=0;
char names[7];
names[0]='P';
names[1]='l';
names[2]='a';
names[3]='y';
names[4]='e';
names[5]='r';
names[6]='1';

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


	  //intitale screen
	  if(menu<1){



	  createChar(0, heart);
	  setCursor(1, 0);
	  write(0);
	  createChar(1, apple);
	  setCursor(1, 3);
	  write(1);
	  createChar(2, block);
	  setCursor(19, 0);
	  write(2);
	  createChar(3, luckybox);
	  setCursor(19, 3);
	  write(3);

	  setCursor(6, 1);
	  print("WELCOME TO");
	  setCursor(8, 2);
	  print("SNAKE!");


	  while (finishuart==0){

	  		 HAL_UART_Receive(&huart3, rxBuffer, 3, 100);



	  		          //   rxBuffer[3] = '\0'; // Null-terminate the received string
	  		             // Process the received data (rxBuffer now contains the string "12:23:43")
	  		             //volume
	  		             if(rxBuffer[0]=='V'){
	  	                        uint8_t v = (rxBuffer[1] - '0') * 10 + (rxBuffer[2] - '0');
	  vol=v;
	  HAL_UART_Transmit(&huart3, "OK",2, 150);

	  		             }
	  		             //health
	  		             else    if(rxBuffer[0]=='H'){
	  	                        uint8_t h = (rxBuffer[1] - '0') * 10 + (rxBuffer[2] - '0');
	  health=h;
	  HAL_UART_Transmit(&huart3, "OK",2 , 100);

	  		             }
	  		             //block
	  		             else if(rxBuffer[0]=='B'){
	  	                        uint8_t b = (rxBuffer[1] - '0') * 10 + (rxBuffer[2] - '0');
	  blocks=b;
	  HAL_UART_Transmit(&huart3, "OK",2 , 100);
	  		             }

	  		             else if(rxBuffer[0]=='F'){
	   finishuart=1;
	  		             }



	  		         }



	  }
	  //menu
	  if(menu==1){
		  if(returnfromchosen==1){

			  //return from choosen
			  returnfromchosen=0;
			  clear();
		  }
if(menuposition==-1)
{	   clear();
menuposition=0;
}
 //cursor updates
createChar(4,menucursor);
setCursor(6, menuposition);
write(4);
//m

if(menuposition==3){
	setCursor(6, 1);
	print(" ");
	setCursor(6, 0);
	print(" ");
	setCursor(6, 2);
	print(" ");
}
else if(menuposition==2){
	setCursor(6, 0);
	print(" ");
	setCursor(6, 1);
	print(" ");
	setCursor(6, 3);
	print(" ");
}
else if(menuposition==1){
	setCursor(6, 3);
	print(" ");
	setCursor(6, 2);
	print(" ");
	setCursor(6, 0);
	print(" ");
}
else if(menuposition==0){
	setCursor(6, 1);
	print(" ");
	setCursor(6, 2);
	print(" ");
	setCursor(6, 3);
	print(" ");
}
//menu
setCursor(7, 0);
print("Start!");
setCursor(7, 1);
print("Mode");
setCursor(7, 2);
print("Setting");
setCursor(7, 3);
print("About");


	  }
//menu choice
	  if(menuchoice==1){
		  if(clearmenuchoice==0){
		  clear();
		  menu=2;

		  //update it when back to main menu
		  clearmenuchoice=1;
		  }
		 if(menuposition==3){
 			 setCursor(0, 0);
			 print("AMIRMAHDI DAMAVANDI");
			 setCursor(0, 1);
			 print("SHAKILA HABIBI");
			 setCursor(0, 2);


			   HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
			   HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

 			   char lcdtime[20];
 			   char lcddate[30];




snprintf(lcdtime,sizeof(lcdtime),"TIME: %02d:%02d:%02d",sTime.Hours,sTime.Minutes,sTime.Seconds);
print(lcdtime);
setCursor(0, 3);
snprintf(lcddate,sizeof(lcddate),"DATE: %d : %02d : %02d",sDate.Year,sDate.Month,sDate.Date);
print(lcddate);

  		 }
		 if(menuposition==1){

			 //set curserchoice
 			 setCursor(0, mode);
			 write(4);
			   if(mode==2){
			 	setCursor(0, 0);
			 	print(" ");
			 	setCursor(0, 1);
			 	print(" ");

			 }
			 else if(mode==1){

			 	setCursor(0, 2);
			 	print(" ");
			 	setCursor(0, 0);
			 	print(" ");
			 }
			 else if(mode==0){
			 	setCursor(0, 1);
	//d
			 	print(" ");
			 	setCursor(0, 2);
			 	print(" ");

			 }
	 			 setCursor(1,0);
	 			 print ("MODE 1");

	 			 setCursor(1,1);
	 			 print ("MODE 2");

	 			 setCursor(1,2);
	 			 print ("MODE 3");

		 }
if(menuposition==2){
	 setCursor(0, settingoption);
				 write(4);
				   if(settingoption==3){
							 	setCursor(0, 0);
							 	print(" ");
							 	setCursor(0, 1);
							 	print(" ");
							 	setCursor(0, 2);
							 	print(" ");
							 }
				   if(settingoption==2){
				 	setCursor(0, 0);
				 	print(" ");
				 	setCursor(0, 1);
				 	print(" ");
				 	setCursor(0, 3);
				 	print(" ");
				 }
				 else if(settingoption==1){
					 	setCursor(0, 3);
					 	print(" ");
				 	setCursor(0, 2);
				 	print(" ");
				 	setCursor(0, 0);
				 	print(" ");
				 }
				 else if(settingoption==0){
				 	setCursor(0, 1);
				 	print(" ");
				 	setCursor(0, 2);
				 	print(" ");
				 	setCursor(0,3);
				 	print(" ");

				 }
	 			   char set[20];

		 			 setCursor(1,0);
		 			 print ("Health");
		 			 setCursor(10,0);
		 			snprintf(set,sizeof(set), "%02d",health);
		 			print(set);
		 			 setCursor(1,1);
		 			 print ("Speed");
		 			 setCursor(10,1);
			 			snprintf(set,sizeof(set), "%02d",speed);
			 			print(set);		 			 setCursor(1,2);
		 			 print ("volume");
		 			 setCursor(10,2);
			 			snprintf(set,sizeof(set), "%02d",vol);
			 			print(set);		 			 setCursor(1,3);
		 			 print ("block");
		 			 setCursor(10,3);
			 			snprintf(set,sizeof(set), "%02d",blocks);
			 			print(set);


			 			 setCursor(14,1);
			 			print ("NAME:");
			 			 setCursor(13,2);
			 			print (names);
			 			setCursor(1,1);
			 					 			 print ("Speed");
			 					 			setCursor(0, 1);
			 					 			print(" ");
			 }

if(menuposition==0){
//initiate
	createChar(5,headsnake);
	createChar(6,snake);
	setCursor(0, 0);
	write(6);
	setCursor(1, 0);
	write(5);

	initialize();

	/*
	setCursor(19,0);
	write(3);

	setCursor(3, 0);
	//v
		write(1);
		grid[0][3]=1;
		setCursor(4, 0);
			write(1);
			grid[0][4]=1;
			setCursor(5, 0);
				write(1);
				grid[0][5]=1;
				setCursor(6, 0);
					write(1);
					grid[0][6]=1;


//	setCursor(15,0);
//	write(2);
//write(5);
grid[0][19]=3;
setCursor(18,3);
	write(2);
grid[3][18]=2;

setCursor(2,2);
write(2);
grid[2][2]=2;

setCursor(3,3);
write(2);
grid[3][3]=2;
//grid[0][15]=2;
*/
//mode1
  // Example game loop with 20 iterations
HAL_Delay(100);

for(int j=0;j<10;j++){
	if(health<=0||point>=99){
		finishgame=1;
		break;
	}
	else{
	   HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
			   HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
minute=sTime.Seconds;

	HAL_Delay(speed*100);

	if(direction==1)currentDir=UP;
	if(direction==2)currentDir=DOWN;
	if(direction==3)currentDir=LEFT;
	if(direction==4)currentDir=RIGHT;
//mode1
if(mode==0)
	moveSnake(segment, currentDir, grid);
//mode2
else if(mode==1){
	moveSnake2(segment, currentDir, grid);

}
//mode3
else if(mode==2){

if(j==8){
	if(speed>=1)
	speed--;
}
	moveSnake3(segment, currentDir, grid);


}

if(j==9)j=0;
}}
if (finishgame==1){
	finishgame=2;
	clear();

	for(int i=1;i<18;i++){

		setCursor(i-1, 2);
		print(" ");
		setCursor(i, 2);
print("FINISH");
HAL_Delay(500);

	}
}
clear();
setCursor(0, 0);
print("Health:");
setCursor(10, 0);
char set[20];
snprintf(set,sizeof(set), "%02d",health);
print(set);

setCursor(0, 1);
print("Point:");
setCursor(10, 1);
set[20];
snprintf(set,sizeof(set), "%02d",point);
//i
print(set);



char prnt[20];
sprintf(prnt, "%02d",health);

HAL_UART_Transmit(&huart3,"NAME:",5, 1000);
HAL_UART_Transmit(&huart3,"PLAYER1",7, 1000);
HAL_UART_Transmit(&huart3,"\n",1, 1000);


HAL_UART_Transmit(&huart3,"health:",7, 1000);
HAL_UART_Transmit(&huart3,prnt,strlen(prnt), 1000);
HAL_UART_Transmit(&huart3,"\n",1, 1000);


 sprintf(prnt, "%02d",point);

HAL_UART_Transmit(&huart3,"points:",7, 1000);
HAL_UART_Transmit(&huart3,prnt,strlen(prnt), 1000);
HAL_UART_Transmit(&huart3,"\n",1, 1000);






HAL_Delay(1000000);


//printGrid(grid);

// Simulate direction change for demonstration
//if (z == 5) currentDir = DOWN;
//if (z == 10) currentDir = LEFT;
//if (z == 15) currentDir = UP;
//if (z == 0) currentDir = RIGHT;






}

}


	  /*
	  if(UARTSETTIME==0){

	  HAL_StatusTypeDef receiveStatus = HAL_UART_Receive(&huart3, (uint8_t *)rxBuffer, 9, HAL_MAX_DELAY);
	         if (receiveStatus == HAL_OK) {
	   		  UARTSETTIME=1;
	             rxBuffer[8] = '\0'; // Null-terminate the received string
	             // Process the received data (rxBuffer now contains the string "12:23:43")
	             time[0]= rxBuffer[0];
	             time[1]= rxBuffer[1];
	             time[2]= rxBuffer[3];
	             time[3]= rxBuffer[4];
	             time[4]= rxBuffer[6];
	             time[5]= rxBuffer[7];


	             //hour
	             // Convert the hours part to an integer
	                        uint8_t hours = (time[0] - '0') * 10 + (time[1] - '0');
mytime.Hours=hours;
	                        // Convert the hours integer to a string for UART transmission
	                        snprintf((char *)hourString, 3, "%02d", hours);


	                        //min
	                        // Convert the hours part to an integer
	                      	 uint8_t min = (time[2] - '0') * 10 + (time[3] - '0');
mytime.Minutes=min;
	                      	 // Convert the hours integer to a string for UART transmission
	                      	 snprintf((char *)minString, 3, "%02d",min);

	                      	 //sec
	                      	  // Convert the hours part to an integer
	                      uint8_t sec = (time[4] - '0') * 10 + (time[5] - '0');
mytime.Seconds=sec;
	                         // Convert the hours integer to a string for UART transmission
	                     snprintf((char *)secString, 3, "%02d", sec);
	                     // Set the RTC time
	                     HAL_RTC_SetTime(&hrtc, &mytime, RTC_FORMAT_BIN);


	         }
	  }
*/
	          //HAL_UART_Transmit(&huart3, hourString, 2, 100);
	        //  HAL_UART_Transmit(&huart3, minString, 2, 100);
	          //HAL_UART_Transmit(&huart3, secString, 2, 100);

/*

	  if(start==1){
if(initiate==0){
	  createChar(0, cactus);
      createChar(1, ground);
	  createChar(2, dino);
	  setCursor(4, 2);
write(2);
initiate=1;
}
for (int k=0;k<20;k++){

	setCursor(k, 3);
		  write(1);
}

for ( cactusposition=19;cactusposition>=0;cactusposition--){
	if(pause==0){
	if(keypadjump==1)
upjump();
if(flagjumpdino==1){

	jumpdinocycle++;
}

if(jumpdinocycle==4){
	downjump();
}
	setCursor(cactusposition, 2);
		  write(0);

print(" ");
HAL_Delay(200);

gameover();

}

	else {
		cactusposition=cactusposition+1;
	}
}
setCursor(0, 2);
print(" ");



	  }*/
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI
                              |RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB|RCC_PERIPHCLK_USART3
                              |RCC_PERIPHCLK_I2C1|RCC_PERIPHCLK_RTC;
  PeriphClkInit.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  PeriphClkInit.USBClockSelection = RCC_USBCLKSOURCE_PLL;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x2000090E;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef sDate = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */

  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 39;
  hrtc.Init.SynchPrediv = 999;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */

  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date
  */
  sTime.Hours = 0x0;
  sTime.Minutes = 0x0;
  sTime.Seconds = 0x0;
  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }
  sDate.WeekDay = RTC_WEEKDAY_MONDAY;
  sDate.Month = RTC_MONTH_JANUARY;
  sDate.Date = 0x1;
  sDate.Year = 0x0;

  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_4BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4294967295;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief USB Initialization Function
  * @param None
  * @retval None
  */
static void MX_USB_PCD_Init(void)
{

  /* USER CODE BEGIN USB_Init 0 */

  /* USER CODE END USB_Init 0 */

  /* USER CODE BEGIN USB_Init 1 */

  /* USER CODE END USB_Init 1 */
  hpcd_USB_FS.Instance = USB;
  hpcd_USB_FS.Init.dev_endpoints = 8;
  hpcd_USB_FS.Init.speed = PCD_SPEED_FULL;
  hpcd_USB_FS.Init.phy_itface = PCD_PHY_EMBEDDED;
  hpcd_USB_FS.Init.low_power_enable = DISABLE;
  hpcd_USB_FS.Init.battery_charging_enable = DISABLE;
  if (HAL_PCD_Init(&hpcd_USB_FS) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USB_Init 2 */

  /* USER CODE END USB_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, CS_I2C_SPI_Pin|LD4_Pin|LD3_Pin|LD5_Pin
                          |LD7_Pin|LD9_Pin|LD10_Pin|LD8_Pin
                          |LD6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : CS_I2C_SPI_Pin LD4_Pin LD3_Pin LD5_Pin
                           LD7_Pin LD9_Pin LD10_Pin LD8_Pin
                           LD6_Pin */
  GPIO_InitStruct.Pin = CS_I2C_SPI_Pin|LD4_Pin|LD3_Pin|LD5_Pin
                          |LD7_Pin|LD9_Pin|LD10_Pin|LD8_Pin
                          |LD6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : MEMS_INT3_Pin MEMS_INT4_Pin */
  GPIO_InitStruct.Pin = MEMS_INT3_Pin|MEMS_INT4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PC0 PC1 PC2 PC3
                           PC4 PC5 PC6 PC7
                           PC8 PC9 PC10 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PD8 PD9 PD10 PD11
                           PD12 PD13 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PD0 PD1 PD2 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PD4 PD5 PD6 PD7 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI2_TSC_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(EXTI2_TSC_IRQn);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
