#include <iostream>
#include <string>
using namespace std;

struct candidate // Structure for candidate with name, votes and percentages
{
    string name;
    float votes, percentage;
};

int main()
{
    
     candidate electionCandidates[5]; // Declaring candidate array
     int total; // Declaring variable for total
     int winnerVotes = 0; // Making initial winnerVotes 0
     string winnerNames; // Making string with names of winner
     
     for (int counter = 0; counter < 5; counter ++) // Getting names and votes for each candidate
     {

         cout << "Please enter the name of the candidate: ";
         getline(cin, electionCandidates[counter].name);
         
         cout << "Please enter the number of votes for the candidate: ";
         cin >> electionCandidates[counter].votes;
     
         cout << endl;
         cin.ignore(100,'\n'); // Ignores null character
     }
     
     for (int counter = 0; counter < 5; counter ++) // Finding total number of votes
         total += electionCandidates[counter].votes;
     
     for (int counter = 0; counter < 5; counter ++) // Finding percentage of votes based on total and entered votes
     {
         electionCandidates[counter].percentage = (electionCandidates[counter].votes / total) * 100;
     }
     
     cout << "The following is the information for the candidates: " << endl;
     
     for (int counter = 0; counter < 5; counter ++) // Outputting name, votes and percentage
     {
         cout << "Candidate Name: " << electionCandidates[counter].name << endl; // Outputting name
         cout << "Candidate's Number of Votes: " << electionCandidates[counter].votes << endl; // Outputting votes
         cout << "Candidate Percentage of Votes: " << electionCandidates[counter].percentage << '%' << endl; // Outputting percentage
         cout << endl;
     }
     
        cout << "The winner(s) of this election is: ";
     
     for (int counter = 0; counter < 5; counter ++) // Finding winner
     {
         if (electionCandidates[counter].votes > winnerVotes) // If votes if winner is greater than previous votes
         {
             winnerVotes = electionCandidates[counter].votes; // Makes votes the higher votes
             winnerNames = electionCandidates[counter].name; // Puts name in string with winners
         }
         else if (electionCandidates[counter].votes == winnerVotes) // If it is a tie
         {
             winnerNames = winnerNames + ", " + electionCandidates[counter].name; // Adding name into winner string
         }
     }
     
    cout << winnerNames << endl; // Outputting winners
     
    return 0;
}
