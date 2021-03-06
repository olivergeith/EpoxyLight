/*
 * EpoxyLight.h
 *
 *  Created on: 11.02.2016
 *      Author: Oliver
 */

#ifndef EpoxyLight_H_
#define EpoxyLight_H_
#include <Adafruit_NeoPixel.h>

class EpoxyLight {
public:
	EpoxyLight(Adafruit_NeoPixel strip);
	virtual ~EpoxyLight();

	void init();
	void setup();

	void drawWheel(int millies, int step, int modulo);
	void drawWheelColorful(int millies, int factor, int step, int modulo);
	void drawWheelRed(int millies);
	void drawWheelBlue(int millies);
	void drawLauflichtRandomColor(int millies, int modulo);
	void drawLauflichtBuildingUp(int millies, int modulo, int step);
	void drawRandomSegment(int millies, int modulo, int offset);
	void drawRandomSegmentV2(int millies, int modulo, int offset);
	void drawRandomSegmentV3(int millies, int modulo);
	void drawTrippleLauflichtWheeled(int millies, int modulo);
	void drawTrippleLauflichtWheeledTronLight(int millies, int modulo, int colorstep);
	void drawPoliceLight(int millies, int modulo);


	void drawBarGraphWheeledColorfull(int millies);
	void drawBarGraphWheeled(int millies);
	int max;
	int delta = 1;
	int ms = 0;
	bool animating;
	int animationStep;

	int color = 0;

	int lauflichtStep1 = 0;
	int lauflichtStep2 = 0;
	int lauflichtStep3 = 0;
	int lauflichtStep4 = 0;
	uint32_t laufLichtColor;
	uint32_t laufLichtColor2;
	uint32_t laufLichtColor3;
	uint32_t laufLichtColor4;

	uint32_t getRandomColor(int brightness);
	uint32_t getColorRotGelbGruen(int brightness);
	uint32_t getColorRotBlauWeiss(int color);
	uint32_t Wheel(byte WheelPos);
	uint32_t getColorWhite(int brightness);
	uint32_t getColorRed(int brightness);

private:
	Adafruit_NeoPixel strip;

};

#endif
