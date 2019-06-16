/*
  ==============================================================================

	MiddleComponent.cpp
	Created: 1 Jun 2019 8:32:20pm
	Author:  Michael Jan

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "MiddleComponent.h"

//==============================================================================
MiddleComponent::MiddleComponent(KeyRepeatAudioProcessor& p) :
	processor(p),
	soundControlsComponent(p),
	fileDropperComponent(p)
{
	addAndMakeVisible(soundControlsComponent);
	addAndMakeVisible(fileDropperComponent);
}

MiddleComponent::~MiddleComponent() {
}

void MiddleComponent::paint(Graphics& g) {
	g.setColour(Colours::purple);
	//g.drawRect(getLocalBounds(), 2.0f);

	Path topLine;
	topLine.addRectangle(0, 0, getWidth(), 2);
	DropShadow ds(Colours::black, getHeight() / 4, { 0, 0 });
	ds.drawForPath(g, topLine);

}

void MiddleComponent::resized() {
	Rectangle<int> rect = getLocalBounds();
	rect.removeFromLeft(rect.getWidth() / 30);
	soundControlsComponent.setBounds(rect.removeFromLeft(rect.getWidth() * 3/5));
	fileDropperComponent.setBounds(rect.reduced(rect.getHeight() / 8) );
}
