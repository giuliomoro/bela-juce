/*
  ==============================================================================

  This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"

//==============================================================================
class BelaBasicExampleApplication  : public JUCEApplication
{
public:
    //==============================================================================
    BelaBasicExampleApplication() {}

    const String getApplicationName() override       { return ProjectInfo::projectName; }
    const String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override       { return true; }

    //==============================================================================
    void initialise (const String& commandLine) override
    {
        component = new MainComponent();
        // This method is where you should put your application's initialisation code..
    }

    void shutdown() override
    {
        // Add your application's shutdown code here..
        delete component;
    }

    //==============================================================================
    void systemRequestedQuit() override
    {
        // This is called when the app is being asked to quit: you can ignore this
        // request and let the app carry on running, or call quit() to allow the app to close.
        quit();
    }

    void anotherInstanceStarted (const String& commandLine) override
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }
private:
    MainComponent* component;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (BelaBasicExampleApplication)
