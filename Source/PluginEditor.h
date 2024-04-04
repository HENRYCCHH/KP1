/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class KP1AudioProcessorEditor  : public juce::AudioProcessorEditor,
                                 public juce::Slider::Listener
{
public:
    KP1AudioProcessorEditor (KP1AudioProcessor&);
    ~KP1AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (juce::Slider* slider) override;


private:
    
    juce::Slider mGainControlSlider;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    KP1AudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KP1AudioProcessorEditor)
};
