#include "eventData.h"

ClassImp(eventData);

eventData::eventData()
{
	Reset();
}
void eventData::Reset()
{
	for (int i=0;i<32;i++) {
		tdc[i] = 0;	
		adc[i] = 0;	
	}

}
void eventData::SetValue(int crate, int slot, int ch, int value)
{	
	if (crate==0) {
		if (slot==17) {
			if (ch>=0 && ch<32) {
				tdc[ch] = value;
			}
		}
		else if (slot==5) {
			if (ch>=0 && ch<32) {
				adc[ch] = value;			
			}
		}
	}
}

void eventData::Calibrate()
{

/*	
	for (int i=0;i<32;i++) {
		if (ch >= 0 && ch<=5) sili_time[ch] = tdc[ch];
		else if (ch == 6) pulser_time = tdc[ch];
		else if (ch == 7) ge_time[0] = tdc[ch];
		else if (ch == 8) ge_time[1] = tdc[ch];
		else if (ch == 9) n1_time = tdc[ch];
		else if (ch == 10) n2_time = tdc[ch];
		else if (ch == 11) bgo6_time = tdc[ch];
		else if (ch == 12) bgo5_time = tdc[ch];
		else if (ch == 13) bgo1_time = tdc[ch];
		else if (ch == 14) bgo4_time = tdc[ch];
		else if (ch == 16) buncher_time = tdc[ch];

		if (ch >= 0 && ch<=5) sili_en[ch] = adc[ch];
		else if (ch == 12) ge_en[1] = adc[ch];
		else if (ch == 14) ge_en[0] = adc[ch];
		else if (ch == 6) n1_en[0] = adc[ch];
		else if (ch == 7) n1_en[1] = adc[ch];
		else if (ch >= 8) n2_en[0] = adc[ch];
		else if (ch >= 8) n2_en[0] = adc[ch];
		else if (ch >= 10) pulser_en = adc[ch];
		else if (ch == 16) bgo6_en = adc[ch];
		else if (ch == 17) bgo5_en = adc[ch];
		else if (ch == 18) bgo1_en = adc[ch];
		else if (ch == 19) bgo4_en = adc[ch];

	}*/
	//SiLi
	for (int i=0; i<6; i++){

		sili_en_raw[i] = adc[i];
		sili_time[i] = tdc[i];
	}
	sili_en[0] = 0.16459*(adc[0] + gRandom->Uniform()) + 7.98992 - 0.16459*0.5;
	sili_en[1] = 0.158567*(adc[1] + gRandom->Uniform())+ 3.38232 - 0.158567*0.5 ;
	sili_en[2] = 0.179119*(adc[2] + gRandom->Uniform()) + -87.821 - 0.179119*0.5;
	sili_en[3] = 0.179943*(adc[3] + gRandom->Uniform()) + -105.219 - 0.179943*0.5;
	sili_en[4] =  0.165956*(adc[4] + gRandom->Uniform()) + 2.25712 -  0.165956*0.5;
	sili_en[5] = 0.174812*(adc[5] + gRandom->Uniform())+ -4.00498 - 0.174812*0.5;

	//Ge

	ge_en_raw[0] = adc[14];
	ge_en_raw[1] = adc[12];
	ge_en[0] = 0.68389*(adc[14] + gRandom->Uniform()) + -26.7755 - 0.68389*0.5; 
	ge_en[1] = 0.684038*(adc[12] + gRandom->Uniform()) + -27.3047 - 0.684038*0.5;
	
	ge_time[0] = tdc[7];
	ge_time[1] = tdc[8];

	//N1 N2

	n1_en[0] = adc[6];
	n1_en[1] = adc[7];
	
	n2_en[0] = adc[8];
	n2_en[1] = adc[9];
	
	n1_time = tdc[9];
	n2_time = tdc[10];

	//Pulser

	pulser_en = adc[10];
	pulser_time = tdc[6];

	//BGOs

	veto_timing_en = adc[13];
	bgo6_en = adc[16];
	bgo5_en = adc[17];
	bgo1_en = adc[18];
	bgo4_en = adc[19];

	bgo6_time = tdc[11];
	bgo5_time = tdc[12];
	bgo1_time = tdc[13];
	bgo4_time = tdc[14];

	//Buncher

	buncher_time = tdc[15];

}
