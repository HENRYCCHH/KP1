/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <cstdio>
#include <iostream>
#include <string>

/*#ifdef DEBUG
#define DBG(msg) std::cout << "DBG: " << msg << std::endl
#else
#define DBG(msg)
#endif*/


/*#ifdef DEBUG
#define DBG(msg) fprintf(stderr, "Debug: %s\n", msg)
#else
#define DBG(msg)
#endif
*/
//==============================================================================
KP1AudioProcessorEditor::KP1AudioProcessorEditor (KP1AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    auto& params = audioProcessor.getParameters();
    juce::AudioParameterFloat* gainParameter = (juce::AudioParameterFloat*)params.getUnchecked(0);
    
    
    mGainControlSlider.setBounds(0, 0, 100, 100);
    mGainControlSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mGainControlSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    mGainControlSlider.setRange(gainParameter->range.start, gainParameter->range.end);
    mGainControlSlider.setValue(*gainParameter);
    mGainControlSlider.addListener(this);
    addAndMakeVisible(mGainControlSlider);
}

KP1AudioProcessorEditor::~KP1AudioProcessorEditor()
{
}

//==============================================================================
void KP1AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.fillAll(juce::Colours::purple);
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Learning JUCE 2", getLocalBounds(), juce::Justification::centred, 1);
}

void KP1AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void KP1AudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    auto& params = audioProcessor.getParameters();
    if (slider ==&mGainControlSlider)
    {
        juce::AudioParameterFloat* gainParameter = (juce::AudioParameterFloat*)params.getUnchecked(0);
        *gainParameter = mGainControlSlider.getValue();
        //std::cout << "DBG: GAIN SLIDER HAS CHANGED" << std::endl;
        //DBG("GAIN SLIDER HAS CHANGED");
    }
    
}
