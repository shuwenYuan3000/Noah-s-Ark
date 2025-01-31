# Noah-s-Ark

## Group Members

- Name: Yuan Shuwen
- UID: 3035638753
- Nickname: Wendy

- Name: Yun Yu
- UID: 3035637503
- Nickname: Rain

## Game Description
This is a game based on game theory.

The background of the game is that:
```
There is a ship of crime, the Noah’s Ark. 
Every year, there will be 500 people either chosen or volunteering to be sent to the ship.
They will have to play games with each other. 
Those who win the game can get off the ship, 
while the losers will have to be locked on board for the rest of their life and be the rats for the illegal drug labs.
```
The rules of the game are very easy:
```
Each player will play with 5 different other players. 
With each opponent, there will be 5 rounds.
In a round, you and your opponent can choose either cooperate or cheat.
The outcome concerning the option will be shown in the table following:
```
| PLAYER 1  |PLAYER 2 |
| ------------- | ------------- |
| `Cooperate` +2 | `Cooperate` +2 |
| `Copperate` 0 | `Cheat` +4  |
| `Cheat` +4 | `Cooperate` 0 |
| `Cheat` -1 | `Cheat` -1  |

**Those who finally win more than 50 coins can get off the board.**

*"So if in all rounds we choose `Cooperate` then we all can get off the board!", the smart said.*

**But for the rest of the coins other than 50,
each one coin can change into 1 million dollars in the real world.**

*Then smiled the greedy.*


**_Now the game starts:_**

Here comes your first opponent, standing in front of you. He is wearing a blue hat, looks kind and cooperative. From his eyes, you can see panic and fear, which reveals the same kind of desire for survival as yours. You need to play with him for 5 rounds. Should you cooperate so that both of you can safely get 10 coins? But will he do the same? Or should you cheat him to gain some more? 

Regardless of your choices and outcomes, there are four more opponents and 20 rounds waiting for you. You will get a description of their appearance, and perhaps you can obtain some information and make the right choice. 

Can you get enough coins and survive the trip? 

## Programme Features/Functions
- Data structure to store the number of coins the player has obtained 
- Data structure to store the choices player has made if the opponent's choice is based on that 
- Generation of random events as one opponent make choices randomly
- Program codes in multiple files
- File Input/Output for loading and saving game status
- Use dynamic memory management for variable used and changed at runtime 

## Programme Features/Functions implemented
- Data structure to store the number of coins the player has obtained 
- Data structure to store the choices player has made if the opponent's choice is based on that 
- Generation of random opponents for different games; Generation of random choices as one opponent make choices randomly
- Program codes in multiple files
- File Input/Output for loading and saving game status
- Use dynamic variable to store highest score of rounds as well as one complete game 

## Compilation and Execution
- Command: $ make noah
- Command: $ ./noah
- Input the player's name
- Input "Yes"/"yes" or "No"/"no" to make choices according to the instructions
