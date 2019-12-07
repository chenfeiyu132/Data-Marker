Dear Diary,

November 18, 2019
- The day is cloudy with a bit of rain
- Setup building environment and got openframework running
- Commited first push to git
- Started work on importing JSON

November 22, 2019
- The sky is clear today, the air is a little brisky
- Import JSON is working properly
- Need to visualize JSON information
- Decide how to store JSON hiearchy for display
- Start working on outlining UI layout

November 23, 2019
- So excited for the flight back to AZ!
- Created JsonLoader object to better store data regarding json file

November 24, 2019
- First day back home! Got to visit an old neighbor who inspired me to do computer science(He taught me my first language)
- Set up test environment after solving many issues with the xcode compiler(took way longer than it seems it should)
- Wrote first test cases for JsonLoader

November 25, 2019
- Hit the gym back home for the first time today! Feels good to be back.
- Researched about loading images from url's (as that will be the main source for Twitter pictures), got test to work.
- Still researching as to how to divide up the window into sections where different outputs could be visualized

November 26, 2019
- Haven't hit the gym yet, I really shouldn't be slacking back home, but the motivation really is just lacking.
- Tested out Gui panel(specifically the toggle feature of ofxGui) which allows the image and text to be hidden or shown.
- Should start working on event listeners to change the layout of the interface based on the number of features being analyzed on the screen.

November 27, 2019
- Had hotpot today with the fam. Basically asian thanksgiving dinner right here.
- Almost encountered the largest crisis due to XCode automatically fixing one of the errors (I hate XCode officially).
- Created some new objects like featurebox and imagebox to organize labeling space
- Started working on gui completion by creating buttons for labeling -> still need to figure out how to fix the issue with defining how many labels there should be.
- Figured out how parameters work in terms of ofxgui.

December 1, 2019
- Finally got back to campus after a crazy few days, extremely tired and not ready to start school again
- Added a few more functionalities to JsonLoader and did some more research with dynamic buttons(creating buttons based on user's choice of options for labeling). It seems like we should treat buttons as ofParameters and use Eventlistener for them to keep track of which buttons are pressed.
- Trying to figure out the best code design still for json processing. The options are creating a whole new class to do all the processing and store variables remotely or doing everything in the ofApp class. 
- Currently trying to develop under the premise that all json processing is done using functions defined in ofApp.h and if design errors arise then will switch to remote object processing.

December 2, 2019
- First day back to school. Got up late for my first class so you already know these two weeks boutta be great!
- Fixed the object structures of textbox and imagebox
- Successfully split json into smaller json objects using vector and created helper functions for json preparation
- Next steps will be integrating json information with text and image boxes and adding the flagging buttons as well as their respective functionalities.

December 6, 2019
- Successfully integrated label buttons and made them dynamic
- Fixed issue with text coloring
- Figured out how ofParameter with buttons and ofEventlistener functions work
- Next step would be making a textfield and connect it with the labelbox

