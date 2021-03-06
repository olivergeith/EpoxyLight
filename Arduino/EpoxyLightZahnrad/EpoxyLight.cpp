/*
 * EpoxyLight.cpp
 *
 *  Created on: 11.02.2016
 *      Author: Oliver
 */

#include "EpoxyLight.h"

EpoxyLight::EpoxyLight(Adafruit_NeoPixel strip) {
	this->strip = strip;
	init();
}

EpoxyLight::~EpoxyLight() {
	// TODO Auto-generated destructor stub
}

void EpoxyLight::init() {
	animating = false;
	max = strip.numPixels();
	animationStep = 0;
	lauflichtStep1 = 0;
	lauflichtStep2 = max / 3;
	lauflichtStep3 = max / 3 * 2;
	lauflichtStep4 = max / 4 * 3;
	laufLichtColor = getColorRed(255);
	color = 0;
}

void EpoxyLight::setup() {
	strip.setBrightness(255);
	strip.begin();
	strip.show(); // Initialize all pixels to 'off'
}

void EpoxyLight::drawWheel(int millies, int step, int modulo) {
	if (!(millies % modulo == 0))
		return;
	animationStep = animationStep + step;
	if (animationStep >= 256)
		animationStep = 0;
	for (int i = 0; i < strip.numPixels(); i++) {
		strip.setPixelColor(i, Wheel(animationStep));
	}
	strip.show();
}

void EpoxyLight::drawWheelColorful(int millies, int factor, int step, int modulo) {
	if (!(millies % modulo == 0))
		return;
	animationStep = animationStep + step;
	if (animationStep >= 256)
		animationStep = 0;
	for (int i = 0; i < strip.numPixels(); i++) {
		strip.setPixelColor(i,
				Wheel(animationStep + i * factor / strip.numPixels()));
	}
	strip.show();
}

void EpoxyLight::drawWheelRed(int millies) {
	if (!(millies % 100 == 0))
		return;
	animationStep = animationStep - 1;
	if (animationStep < 0)
		animationStep = strip.numPixels() - 1;
	for (int i = 0; i < strip.numPixels(); i++) {
		strip.setPixelColor(i, 0, 48, 80);
	}

	strip.setPixelColor((animationStep + 0) % strip.numPixels(), 64, 0, 0);
	strip.setPixelColor((animationStep + 1) % strip.numPixels(), 255, 0, 0);
	strip.setPixelColor((animationStep + 2) % strip.numPixels(), 255, 0, 0);
	strip.setPixelColor((animationStep + 3) % strip.numPixels(), 255, 0, 0);
	strip.setPixelColor((animationStep + 4) % strip.numPixels(), 255, 0, 0);
	strip.setPixelColor((animationStep + 5) % strip.numPixels(), 255, 0, 0);
	strip.setPixelColor((animationStep + 6) % strip.numPixels(), 255, 0, 0);
	strip.setPixelColor((animationStep + 7) % strip.numPixels(), 64, 0, 0);

	strip.show();
}

void EpoxyLight::drawWheelBlue(int millies) {
	if (!(millies % 50 == 0))
		return;
	animationStep = animationStep - 1;
	if (animationStep < 0)
		animationStep = strip.numPixels() - 1;
	for (int i = 0; i < strip.numPixels(); i++) {
		strip.setPixelColor(i, 64, 0, 0);
	}

	strip.setPixelColor((animationStep + 0) % strip.numPixels(), 0, 0, 64);
	strip.setPixelColor((animationStep + 1) % strip.numPixels(), 0, 0, 255);
	strip.setPixelColor((animationStep + 2) % strip.numPixels(), 0, 0, 255);
	strip.setPixelColor((animationStep + 3) % strip.numPixels(), 0, 0, 255);
	strip.setPixelColor((animationStep + 4) % strip.numPixels(), 0, 0, 255);
	strip.setPixelColor((animationStep + 5) % strip.numPixels(), 0, 0, 255);
	strip.setPixelColor((animationStep + 6) % strip.numPixels(), 0, 0, 255);
	strip.setPixelColor((animationStep + 7) % strip.numPixels(), 0, 0, 64);

	strip.show();
}



void EpoxyLight::drawBarGraphWheeled(int millies) {
	if (millies % 100 == 0) {
		if (lauflichtStep1 == strip.numPixels()) {
			lauflichtStep1 = 0;
			laufLichtColor = laufLichtColor + 16;
			if (laufLichtColor >= 256)
				laufLichtColor = 0;
		}
		for (int i = 0; i < strip.numPixels(); i++) {
			if (i <= lauflichtStep1) {
				strip.setPixelColor(i, Wheel(laufLichtColor));
			} else {
				strip.setPixelColor(i, 0, 0, 0);
			}
		}
		lauflichtStep1 = lauflichtStep1 + 1;
		strip.show();
	}
}

void EpoxyLight::drawBarGraphWheeledColorfull(int millies) {
	if (millies % 100 == 0) {
		int center = strip.numPixels() / 2 + 1;
		if (lauflichtStep1 == center) {
			lauflichtStep1 = 0;
			laufLichtColor = laufLichtColor + 16;
			if (laufLichtColor >= 256)
				laufLichtColor = 0;
		}
		for (int i = 0; i < strip.numPixels(); i++) {
			if (i <= lauflichtStep1 || i >= strip.numPixels() - lauflichtStep1) {
				strip.setPixelColor(i, Wheel(laufLichtColor + i * 4));
			} else {
				strip.setPixelColor(i, 0, 0, 0);
			}
		}
		lauflichtStep1 = lauflichtStep1 + 1;
		strip.show();
	}
}


void EpoxyLight::drawRandomSegment(int millies, int modulo, int offset) {

	if (millies % modulo == 0) {

		lauflichtStep1 = random(strip.numPixels());
		lauflichtStep2 = random(strip.numPixels());
		lauflichtStep3 = random(strip.numPixels());
		lauflichtStep4 = random(strip.numPixels());

		int rand = random(255);

		animationStep = animationStep + 4;
		if (animationStep >= 256)
			animationStep = 0;

		for (int i = 0; i < strip.numPixels(); i++) {
			if (i == lauflichtStep1 || i==lauflichtStep1+1) {
				strip.setPixelColor(i, Wheel(rand));
			} else if (i == lauflichtStep2){
				strip.setPixelColor(i, Wheel(rand+offset));
			} else if (i == lauflichtStep3){
				strip.setPixelColor(i, Wheel(rand+2*offset));
			} else if (i == lauflichtStep4){
				strip.setPixelColor(i, Wheel(rand+3*offset));
			} else {
				strip.setPixelColor(i, 0, 0, 0);
			}
		}
		strip.show();
	}
}

void EpoxyLight::drawRandomSegmentV2(int millies, int modulo, int offset) {

	if (millies % modulo == 0) {

		int rand = random(255);

		for (int i = 0; i < strip.numPixels(); i++) {
			int onOff = random(2);
			if (onOff == 1){
//				uint32_t pcolor = strip.getPixelColor(i);
//				if (pcolor == 0){
					strip.setPixelColor(i, Wheel(rand+i*3));
//				}else{
//					strip.setPixelColor(i, 0, 0, 0);
//				}
			}else{
				strip.setPixelColor(i, 0, 0, 0);

			}

		}
		strip.show();
	}
}

void EpoxyLight::drawRandomSegmentV3(int millies, int modulo) {

	if (millies % modulo == 0) {

		int rand = random(255);
		int colorOffset = random(9);

		for (int i = 0; i < strip.numPixels(); i++) {
			int onOff = random(2);
			if (onOff == 1){
				strip.setPixelColor(i, Wheel(rand+i*colorOffset));
			}else{
				strip.setPixelColor(i, 0, 0, 0);

			}

		}
		strip.show();
	}
}


void EpoxyLight::drawTrippleLauflichtWheeled(int millies, int modulo) {
	if (millies % modulo == 0) {
		//animationStep = animationStep + 1;
		if (animationStep >= 256)
			animationStep = 0;

		if (lauflichtStep1 == strip.numPixels()) {
			animationStep = animationStep + 1;
			lauflichtStep1 = 0;
		}
		if (lauflichtStep2 == strip.numPixels()) {
			animationStep = animationStep + 1;
			lauflichtStep2 = 0;
		}
		if (lauflichtStep3 == strip.numPixels()) {
			animationStep = animationStep + 1;
			lauflichtStep3 = 0;
		}

		laufLichtColor = Wheel(animationStep);
		for (int i = 0; i < strip.numPixels(); i++) {
			if (i == lauflichtStep1 //
			|| i == lauflichtStep2 //
			|| i == lauflichtStep3 //
					) {
				strip.setPixelColor(i, laufLichtColor);
			} else {
				strip.setPixelColor(i, 0, 0, 0);
			}
		}
		lauflichtStep1++;
		lauflichtStep2++;
		lauflichtStep3++;
		strip.show();
	}
}

int inkrement = 1;
void EpoxyLight::drawTrippleLauflichtWheeledTronLight(int millies, int modulo, int colorstep) {
	if (millies % modulo == 0) {
		int upDown = random(50);
		if (upDown == 0){
			inkrement = inkrement * (-1);
		}

		if (animationStep >= 256)
			animationStep = 0;

		animationStep = animationStep + inkrement*colorstep;

		// in case vorwaerts
		if (lauflichtStep1 == strip.numPixels()) {
			lauflichtStep1 = 0;
		}
		if (lauflichtStep2 == strip.numPixels()) {
			lauflichtStep2 = 0;
		}
		if (lauflichtStep3 == strip.numPixels()) {
			lauflichtStep3 = 0;
		}

		// in case r�ckw�rts
		if (lauflichtStep1 == -1) {
			lauflichtStep1 = strip.numPixels()-1;
		}
		if (lauflichtStep2 == -1) {
			lauflichtStep2 = strip.numPixels()-1;
		}
		if (lauflichtStep3 == -1) {
			lauflichtStep3 = strip.numPixels()-1;
		}

		laufLichtColor = Wheel(animationStep);
		for (int i = 0; i < strip.numPixels(); i++) {
			if (i == lauflichtStep1 || i == lauflichtStep1 +1//
			|| i == lauflichtStep2 || i == lauflichtStep2 +1//
			|| i == lauflichtStep3 || i == lauflichtStep3 +1//
					) {
				strip.setPixelColor(i, laufLichtColor);
			} else {
				strip.setPixelColor(i, 0, 0, 0);
			}
		}
		lauflichtStep1 = lauflichtStep1 +inkrement;
		lauflichtStep2 = lauflichtStep2 +inkrement;
		lauflichtStep3 = lauflichtStep3 +inkrement;
		strip.show();
	}
}


void EpoxyLight::drawLauflichtRandomColor(int millies, int modulo) {
	if (millies % modulo == 0) {
		if (lauflichtStep1 == strip.numPixels()) {
			lauflichtStep1 = 0;
			laufLichtColor = getRandomColor(255);
		}
		if (lauflichtStep2 == strip.numPixels()) {
			lauflichtStep2 = 0;
		}
		for (int i = 0; i < strip.numPixels(); i++) {
			if (i == lauflichtStep1 || i == lauflichtStep2) {
				strip.setPixelColor(i, laufLichtColor);
			} else {
				strip.setPixelColor(i, 0, 0, 0);
			}
		}
		lauflichtStep1++;
		lauflichtStep2 = lauflichtStep1+1;
		strip.show();
	}
}



void EpoxyLight::drawLauflichtBuildingUp(int millies, int modulo, int step) {
	if (millies % modulo == 0) {
		if (max == 0) {
			color = random(256);
		}
		animationStep++;
		if (animationStep == max) {
			animationStep = 0;
			max--;
			if (max == 0)
				max = strip.numPixels();
		}
		for (int i = 0; i < max; i++) {
			if (i == animationStep
					|| i == animationStep - 1 | i == animationStep - 2) {
				strip.setPixelColor(i, Wheel(color + (max - 1) * step));
			} else {
				strip.setPixelColor(i, 0, 0, 0);
			}
		}
		for (int i = max; i < strip.numPixels(); i++) {
			strip.setPixelColor(i, Wheel(color + i * step));
		}
	}
	strip.show();
}



void EpoxyLight::drawPoliceLight(int millies, int modulo) {
	if (millies % modulo == 0) {
		if (lauflichtStep1 == strip.numPixels()) {
			lauflichtStep1 = 0;
		}
		for (int i = 0; i < strip.numPixels(); i++) {
			if (i == lauflichtStep1) {
				strip.setPixelColor(i, 0, 0, 255);
			} else if (i
					== (strip.numPixels() / 2 + lauflichtStep1)
							% strip.numPixels()) {
				strip.setPixelColor(i, 255, 0, 0);
			} else {
				strip.setPixelColor(i, 0, 0, 0);
			}
		}
		lauflichtStep1 = lauflichtStep1 + 1;
	}
	strip.show();
}


uint32_t EpoxyLight::getRandomColor(int brightness) {
	return Wheel(random(256));
}

uint32_t EpoxyLight::getColorRotGelbGruen(int color) {
	switch (color) {
	default:
	case 0:
		return Wheel(0);
	case 1:
		return Wheel(16);
	case 2:
		return Wheel(64);

	}
}

uint32_t EpoxyLight::getColorRotBlauWeiss(int color) {
	switch (color) {
	default:
	case 0:
		return strip.Color(255, 0, 0);
	case 1:
		return strip.Color(0, 0, 255);
	case 2:
		return strip.Color(192, 192, 192);
	}
}

uint32_t EpoxyLight::getColorRed(int brightness) {
	return strip.Color(brightness, 0, 0);
}

uint32_t EpoxyLight::getColorWhite(int brightness) {
	return strip.Color(brightness, brightness, brightness);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t EpoxyLight::Wheel(byte WheelPos) {
	WheelPos = 255 - WheelPos;
	if (WheelPos < 85) {
		return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
	}
	if (WheelPos < 170) {
		WheelPos -= 85;
		return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
	}
	WheelPos -= 170;
	return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


