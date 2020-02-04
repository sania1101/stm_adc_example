
#include "main.h"

UART_HandleTypeDef huart4;
ADC_HandleTypeDef hadc1;

int main(void)
{

  HAL_Init();
  SystemClock_Config();

  MX_GPIO_Init();
  huart4 = MX_UART4_Init(huart4);
  MX_ADC1_Init(hadc1);
	HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_14);
  while (1)
  {
    char msg_0[]="are you want ON ACD or LED_13(ACD - a, LED - l)\r\n";
		char a[]="a";
		char l[]="l";
		char unswere[1];
		char new_line[]="\r\n";
		HAL_UART_Transmit_IT( &huart4, msg_0,(sizeof msg_0)/sizeof(char));
		HAL_Delay(100);
		
	HAL_UART_Receive_IT(&huart4,unswere,(sizeof unswere)/sizeof(char));
		HAL_Delay(100);
		
		HAL_UART_Transmit_IT( &huart4,unswere,(sizeof unswere)/sizeof(char)); 
		HAL_Delay(100);
		
		HAL_UART_Transmit_IT( &huart4,new_line,(sizeof new_line)/sizeof(char)); 
		HAL_Delay(100);
		
	if(unswere[0]==a[0]){
				char msg_1[]="are you want one write ADC value or infinity ADC value()(1/2)\r\t";
				char one[]="1";
				char two[]="2";
				
				HAL_UART_Transmit_IT( &huart4,msg_1,(sizeof msg_1)/sizeof(char)); 
				HAL_Delay(100);
		
				HAL_UART_Receive_IT(&huart4,unswere,(sizeof unswere)/sizeof(char));
				HAL_Delay(100);
				
				HAL_UART_Transmit_IT( &huart4,unswere,(sizeof unswere)/sizeof(char)); 
				HAL_Delay(100);
				
				HAL_UART_Transmit_IT( &huart4,new_line,(sizeof new_line)/sizeof(char)); 
				HAL_Delay(100);
			
				if(unswere[0]==one[0]){
							uint16_t b = 0;
							uint8_t str[]="r/n";
							float c = 0;
						/* USER CODE END WHILE */
							HAL_ADC_Start(&hadc1);
							HAL_ADC_PollForConversion(&hadc1,100);
							//i = HAL_ADC_GetValue(&hadc1);
							b = HAL_ADC_GetValue(&hadc1);
							HAL_ADC_Stop(&hadc1);
						
							c = (3.3*b)/4096;
							char strr[30];
							sprintf(strr,"adc range - %04f  V\r\n",c);
							HAL_UART_Transmit_IT( &huart4,strr,26); 
							HAL_Delay(100);
				}
				else{
					while(1){
							uint16_t b = 0;
							uint8_t str[]="r/n";
							float c = 0;
						/* USER CODE END WHILE */
							HAL_ADC_Start(&hadc1);
							HAL_ADC_PollForConversion(&hadc1,100);
							//i = HAL_ADC_GetValue(&hadc1);
							b = HAL_ADC_GetValue(&hadc1);
							HAL_ADC_Stop(&hadc1);
						
							c = (3.3*b)/4096;
							char strr[30];
							sprintf(strr,"adc range - %04f  V\r\n",c);
							HAL_UART_Transmit_IT( &huart4,strr,26); 
							HAL_Delay(100);
					}
				}
			}else{
				char msg_2[] = "on LED_13"; 
				
				HAL_UART_Transmit_IT( &huart4,msg_2,(sizeof msg_2)/sizeof(char)); 
				HAL_Delay(100);
				HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_13);
				HAL_Delay(10000);
				HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_13);
		}
		
  }
}

