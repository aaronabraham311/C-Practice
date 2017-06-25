#include <iostream>
#include <string>

using namespace std;

int main()
{
    string userInitialAnswer; // Declaring variable
    
    cout<<"You stand in a dank cave. To the left you see a dark door, in front you see a ladder, and to the right, you see a wooden door. Which way do you go? Please input either 'Right', 'Straight', or 'Left':"<<endl;
    getline(cin,userInitialAnswer); // Getting input for first set of decisions
    
    if ( userInitialAnswer == "Right") // If user chooses to go through wooden door
    {
        string userWoodenDoorAnswer1; // Declaring variable
        
        cout<<"\nAs you open the wooden door, you see another dank cave, however this cave has two things inside of it: an old man with a staff, and a small potion of the table. Do you talk to the man or drink the potion? Please input either 'Talk to the man' or 'Drink the potion':"<<endl;
        getline(cin,userWoodenDoorAnswer1); // Getting input for either man or potion
        
        if ( userWoodenDoorAnswer1 == "Talk to the man") // If user chooses to talk to the man
        {
            int userWoodenDoorAnswer2; //Declaring variable
            
            cout<<"\nThe old man eyes you curiosuly. He twiddles with his staff, unsure of what to say to you. After a few awkward moments of silence, he finally speaks up: 'Young quester, if you seek the treasures and to get out of this cave alive, answer this question: What is 5*6+4+7/7*3-2'"<<endl;
            cin>>userWoodenDoorAnswer2; // Asking math question and getting input
            
            if ( userWoodenDoorAnswer2 == 35) // If user answers 35
            {
                cout<<"\nYour answer still hangs in the air. The old man answers, 'Hmmm, great answer. You are the only one to succesfully solve this math problem. In reward, you get to enter the Room of Glory. Riches and freedom awaits. Have fun'. You enter a door that suddenly appears out of nowhere. As you enter, the glare of gold coins and the sunlight from outside blind you. Slowly, a smile creeps on your face."<<endl;
            }
            else // If user answers something other than 35
            {
                cout<<"\nYour answer still hangs in the air. The old man answers, 'Hmmm, interesting. You are the only one to not succesfully solve this math problem. In punishment, embrace DEATH!!' He suddenly strikes you down with his staff. Blackness engulfs your eyes. Game over"<<endl;
            }
        }
        else if ( userWoodenDoorAnswer1 == "Drink the potion") // User chooses to drink the potion
        {
            string userWoodenDoorAnswer3; // Declaring variables
            
            cout<<"\nAs you drink the potion, a weird feeling comes upon you. You feel your insides shrinking, and the room seems larger. As the tiny version of yourself looks around, you see a small door and a small hole in the wall. Which one do you walk through? Please enter either 'Small door' or 'Small hole':"<<endl;
            getline(cin,userWoodenDoorAnswer3); // Getting input on either small door or small hole
            
            if ( userWoodenDoorAnswer3 == "Small door")
            {
                cout<<"\nAs you enter the small door, a strange smell wafts in your nose. Soon you are on the ground, trembling with uncontrolled coughs. You scream for help, knowing that it will be useless. As blackness surrounds your vision, one thought goes through your head 'Chlorine gas'. Game over"<<endl; // If user chooses small door
            }
            else if ( userWoodenDoorAnswer3 == "Small hole")
            {
                cout<<"\n'It's so dark' you think. You feel a strange dampness on your neck. As you continue travelling down this hole, you trip on something. When picking it up, you find a switch, and turn it on. It's a flashlight! However, your brief moment of delight is over when you see a hungry cat staring out you. It opens its wide jaws, and eats you. Game over"<<endl;
            }
            else // If user enters something else
            {
                cout<<"Don't fool around. Try again."<<endl;
            }
        }
        else // If user enters spmething
        {
            cout<<"\nDon't fool around. Try again"<<endl;
        }
    
    }
    else if ( userInitialAnswer == "Straight") // If user chooses to go straight
    {
        string userLadderAnswer1; // Declaring variable
        
        cout<<"\nRung by rung, you climb. Your heart beats, fearful for what is at the top of the ladder. Soon enough, you scramble to the top edge. All you see is a dusty cave, devoid of anything, with just two entrances, one at your left, and one at your right. Suddenly, a walking, breathing skeleton appears out of the left door. Also, a green, slimy zombie appears out of the right door. Both say, 'Come, adventurer, talk to me.'. Which one do you want to talk to, the zombie or the skeleton? Please input either 'Skeleton' or 'Zombie'."<<endl;
        getline(cin,userLadderAnswer1); // Getting input on if user chooses skeleton or zombie
        
        if ( userLadderAnswer1 == "Skeleton") // If user chooses to
        {
            string userLadderAnswer2;
            
            cout<<"\nAs you approach the skeleton, the bony hands reach and touch its face. Suddenly, it pulls its face! It  was a mask. Undeneath the mask, a human face peers at you! 'Hello, my name is Doug. I'm in disguise, as there are many dangerous creatures in this maze. You see, I found the exit from this horrible place, but I need the strength of two people. Please, help me!' What do you do: do you follow Doug, or do you decline his offer? Please enter either 'Follow Doug' or 'Decline offer'."<<endl;
            getline(cin, userLadderAnswer2); // Getting input of if user wants to follow Doug of decline offer
            
            if ( userLadderAnswer2 == "Follow Doug") // If user chooses to follow Doug
            {
                cout<<"\n'Thank you very much, young adventurer. Here, follow me' Doug cheerfully replies. As you walk down the cave, he tells you of his life story. He had come from Copenhagen, and was an avid spelunker. While on a journey in the Mammoth cave system in Kentucky, USA, he had fallen in a a hole, and woke up inside this huge cave system. Soon, it was quiet, and we come towards a rock, that seems to be blocking a hole. As you approach it, you feel a sudden pain in your ribs. You look, and you see a knife wedged in your ribs, blood pouring down your shirt. With horror, you look at Doug. 'I'm sorry, but there is no exit. I had to kill you to get what I needed.' Blackness emcompasses your vision. Game over."<<endl;
            }
            
            else if ( userLadderAnswer2 == "Decline offer") // If user chooses to decline offer
            {
                cout<<"\n'Sorry, I have to decline your offer. Thank you, though' You sidestep him and walk through the doorway. In utter blindness, you stumble your way around. You trip over rocks, and rip your shirt with stones. 'Why didn't I go with Doug?' you wonder. Suddenly, your foot goes through the ground! You fall, realizing that you missteped of the path and fell off a cliff. "<<endl;
            }
            else // If user enters spmething
            {
                cout<<"\nDon't fool around. Try again"<<endl;
            }
        }
        else if ( userLadderAnswer1 == "Zombie") // If user chooses to talk to zombie
        {
            string userLadderAnswer3; // Declaring variable
            cout<<" \n'Follow... me.. please..' the zombie struggles to say. Do you want to follow him, to whatever he may direct you to, or will you decide to ditch the zombie? Please enter either 'Follow the zombie' or 'Ditch the zombie'"<<endl;
            getline(cin, userLadderAnswer3); // Getting input on whether user would like to follow or ditch zombie
            
            if ( userLadderAnswer3 == "Follow the zombie") // If user wants to follow the zombie
            {
                cout<<"\n'Thank... you' the zombie struggles to say. He walks slowly, with an ambling gait. He leads through many turns in the darkness leaving you with no idea how to escape. 'Maybe he will lead me to the treasure' you think. Suddenly, out of the darkness, a hand reaches and grabs your shoulder. You spin around, and there, facing you, is 10 zombies. 'I... am...sorry....need..BRAIN!' the zombie shouts. He runs over, a splitting pain in your head, and blackness is all you see. Game over."<<endl;
            }
            else if ( userLadderAnswer3 == "Ditch the zombie") // If user wants to ditch the zombie
            {
                cout<<"\nAfraid that the zombie might take you and eat your brains, you run past him and into the dark doorway. You can see nothing. No light. No fire. The sound of the crunching of rocks is the only thing that accompanies you, but not for long. Soon, you hear a loud sound coming to your left. It sounds like a rushing river! You run even faster, desperate for some thirst. Suddenly, you feel no ground, and only water. You fall into the water, struggling to gain breath. You desperately try to swim ashore, but the strong current pushes you towards a drop. You fall over the drop. A sharp CRACK from your spine resonates through the air as you crash into a rock. You are dead. Game over."<<endl;
            }
            else // If user enters something else
            {
                cout<<"Don't fool around. Try again."<<endl;
            }

        }
        else // If user enters something else
        {
            cout<<"Don't fool around. Try again."<<endl;
        }

    }
    else if ( userInitialAnswer == "Left") // If user chooses to go left
    {
        string userDarkDoorAnswer1; // Declaring variable
        
        cout<<"\nAs you enter the dark door, you hear a mighty sound of water on rocks. Eagerly, you run towards the exit, and you suddenly screech to a stop. Before you, you see a rickety, old bridge with planks missing in the miidle, that is hung over a 500m drop with a raging stream below you. Groaning with thirst, you try to find a way to the bottom, but you see a narrow ledge, that might, just might, lead you to that river. What do you do? Please enter either 'Cross the bridge' or 'Walk on narrow ledge':"<<endl;
        getline(cin,userDarkDoorAnswer1); // Getting input on whether user should cross bridge or ledge
        
        if ( userDarkDoorAnswer1 == "Cross the bridge") // If they choose to cross the bridge
        {
            string userDarkDoorAnswer2; // Declaring variable
            
            cout<<"\nAs you cross the bridge, it swoons over and over. Planks keep falling, and adrenaline is upon you. You decide to run it, and take a risk, rather then spending more time on this sketchy bridge. Luckily, you make it. As you continue on a path from the bridge, you enter another cave. This time, the cave has a mirror that looks like a portal, and a slide dropping you down from the room. What do you choose? Please enter either 'Go through portal' or 'Go on slide"<<endl;
            getline(cin,userDarkDoorAnswer2);// Must choose whether to go through portal or slide. Getting input
            
            if ( userDarkDoorAnswer2 == "Go through portal") // If user goes through portal
            {
                cout<<"\nAs you step into the mirror, you feel a watery surface as you transport yourself. As you step out, you suddenly fall 5m from the air onto sand. As you look up, you realize that the portal transported you to an island in the middle of the ocean. Have fun! Game over"<<endl;
            }
            else if ( userDarkDoorAnswer2 == "Go on slide") // If user goes on slide
            {
                cout<<"\nThe wind is in your hair as you whip down the slide. 'Wheeee!' you yell as go spiralling downwards, and downwards, and downwards. Soon you fall asleep, even though you're still on the slide. After a nice nap, it starts to get uncomfortably hot. As you open your eyes, you see a lake of fire approaching you. A single tear drips down your cheek. Game over."<<endl;
            }
            else // If user enters something else
            {
                cout<<"\nDon't fool around. Try again."<<endl;
            }
        }
        else if ( userDarkDoorAnswer1 == "Walk on narrow ledge") // If user goes on ledge
        {
            string userDarkDoorAnswer3; // Declaring variable
            
            cout<<"\nAs you walk on the narrow ledge, you feel sweat dripping down every pore in your body. As you look down, you see the mighty river, rushing towards an unknown destination. For several minutes, you continue, step by step, until you come to the end. After the ledge, you see a rope dropping down towards the river, and a ladder scaling up the wall. On one hand, you could get water, and the other hand, the ladder could direct you towards treasure. Which one do you choose: the rope or the ladder. Please input either 'Rope' or 'Ladder':"<<endl;
            cin>>userDarkDoorAnswer3; // Getting input on whether user wants to go on rope or ladder
            
            if (userDarkDoorAnswer3 == "Rope") // If user chooses to go on rope
            {
                cout<<"\nCarefully, you crouch down, ready to drop down towards the water and drink. Even the thought of water makes you thirsty. Inch by inch, you descend. Suddenly, a bat flys up, hits you and falls. After a moment of silence, a mob of bats, thousands upon thousands, fly towards. In fear, you let go. You fall, towards your death. Splash! Game over."<<endl;
            }
            
            else if ( userDarkDoorAnswer3 == "Ladder") // If user chooses to go on ladder
            {
                cout<<"\nAs you put your hands on it, the coldness of the wooden rungs shivers up your spine. Putting on a confident face, you climb. After several minutes of climbing, you see a faint light. Joy leaps in your heart. You continue, the sight of light driving you onwards. You soon reach the hole. You barely manage to squeeze through, and start to crawl. On, and on, and on, and ... you fall out. Green grass tickles your cheeks. Well done, you got out of the cave. Game over."<<endl;
            }
            else // If user enters spmething
            {
                cout<<"\nDon't fool around. Try again"<<endl;
            }
        }
        else // If user enters spmething
        {
            cout<<"\nDon't fool around. Try again"<<endl;
        }
    }
    else // If user enters something else
    {
        cout<<"Don't fool around. Try again."<<endl;
    }
    
    return 0;
}
