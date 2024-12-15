#include "button.h"
int KeyReg0_1 = NORMAL_STATE;
int KeyReg0_2 = NORMAL_STATE;
int KeyReg0_3 = NORMAL_STATE;
int KeyReg1_1 = NORMAL_STATE;
int KeyReg2_1 = NORMAL_STATE;
int KeyReg3_1 = NORMAL_STATE;
int KeyReg1_2 = NORMAL_STATE;
int KeyReg2_2 = NORMAL_STATE;
int KeyReg3_2 = NORMAL_STATE;
int KeyReg1_3 = NORMAL_STATE;
int KeyReg2_3 = NORMAL_STATE;
int KeyReg3_3 = NORMAL_STATE;

int TimeOutForKeyPress =  500;
int button1_pressed = 0;
int button1_long_pressed = 0;
int button1_flag = 0;

int button2_pressed = 0;
int button2_long_pressed = 0;
int button2_flag = 0;

int button3_pressed = 0;
int button3_long_pressed = 0;
int button3_flag = 0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

int isButton1LongPressed(){
	if(button1_long_pressed == 1){
		button1_long_pressed = 0;
		return 1;
	}
	return 0;
}

int isButton2LongPressed(){
	if(button2_long_pressed == 1){
		button2_long_pressed = 0;
		return 1;
	}
	return 0;
}

int isButton3LongPressed(){
	if(button3_long_pressed == 1){
		button3_long_pressed = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(){
	//TODO
	//HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	button1_flag = 1;
	button2_flag = 1;
	button3_flag = 1;
}

void getKey1Input(){
  KeyReg2_1 = KeyReg1_1;
  KeyReg1_1 = KeyReg0_1;
  // Add your key
  KeyReg0_1 = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);

  if ((KeyReg1_1 == KeyReg0_1) && (KeyReg1_1 == KeyReg2_1)){
    if (KeyReg2_1 != KeyReg3_1){
      KeyReg3_1 = KeyReg2_1;

      if (KeyReg3_1 == PRESSED_STATE){
        TimeOutForKeyPress = 500;
        //subKeyProcess();
        button1_flag = 1;
      }

    }else{
        TimeOutForKeyPress --;
        if (TimeOutForKeyPress == 0){
        	TimeOutForKeyPress = 500;
        	if (KeyReg3_1 == PRESSED_STATE){
        		//subKeyProcess();
        		button1_flag = 1;
        	}
        }
    }
  }
}

void getKey2Input(){
	  KeyReg2_2 = KeyReg1_2;
	  KeyReg1_2 = KeyReg0_2;
	  // Add your key
	  KeyReg0_2 = HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin);

	  if ((KeyReg1_2 == KeyReg0_2) && (KeyReg1_2 == KeyReg2_2)){
	    if (KeyReg2_2 != KeyReg3_2){
	      KeyReg3_2 = KeyReg2_2;

	      if (KeyReg3_2 == PRESSED_STATE){
	        TimeOutForKeyPress = 500;
	        //subKeyProcess();
	        button2_flag = 1;
	      }

	    }else{
	        TimeOutForKeyPress --;
	        if (TimeOutForKeyPress == 0){
	        	TimeOutForKeyPress = 500;
	        	if (KeyReg3_2 == PRESSED_STATE){
	        		//subKeyProcess();
	        		button2_flag = 1;
	        	}
	        }
	    }
	  }
}

void getKey3Input(){
	  KeyReg2_3 = KeyReg1_3;
	  KeyReg1_3 = KeyReg0_3;
	  // Add your key
	  KeyReg0_3 = HAL_GPIO_ReadPin(button3_GPIO_Port, button3_Pin);

	  if ((KeyReg1_3 == KeyReg0_3) && (KeyReg1_3 == KeyReg2_3)){
	    if (KeyReg2_3 != KeyReg3_3){
	      KeyReg3_3 = KeyReg2_3;

	      if (KeyReg3_3 == PRESSED_STATE){
	        TimeOutForKeyPress = 500;
	        //subKeyProcess();
	        button3_flag = 1;
	      }

	    }else{
	        TimeOutForKeyPress --;
	        if (TimeOutForKeyPress == 0){
	        	TimeOutForKeyPress = 500;
	        	if (KeyReg3_3 == PRESSED_STATE){
	        		//subKeyProcess();
	        		button3_flag = 1;
	        	}
	        }
	    }
	  }
}
