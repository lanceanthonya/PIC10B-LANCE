////
////  testroom.cpp
////  hw1
////
////  Created by Lance Aquino on 4/15/22.
////
//
//#include <iostream>
//#include <string>
//#include "person.h"
//#include "game.h"
//
//using namespace std;
//int main(){
//    
//     
//    // Person class test code, status: works
//    std::string playero_name, playerx_name;
//    cout<<"input player O name: ";
//    getline(cin, playero_name);
//    Person player_o = Person(playero_name);
//    cout<<"input player X name: ";
//    getline(cin, playerx_name);
//    Person player_x = Person(playerx_name);
//    
//    // Game Class test code
//
//    Game cur_game = Game(player_o,player_x);
//    
//    cur_game.display(); // emptysstate
//    
//    char x_cor, y_cor;
////    bool move_is_valid;
//    for (size_t num_turns = 1; num_turns <=9; ++ num_turns){
//        cin.clear();
//
//        cout << "Input coordinates: ";
//        cin>> x_cor >> y_cor;
//        bool valid_move = cur_game.make_move(player_o,x_cor, y_cor);
//        if (valid_move)
//        {
//            cur_game.display();
//            
//        }
//        else
//        {
//            cout << "ERROR: Invalid move \n";
//
//        }
//        if (cur_game.player_has_won_match(player_o))
//        {
//            cout<< player_o.get_name() << " has won the match";
//            break;
//        }
//
//    }
//
//    
//    
//    
//    
//    return 0;
//}
//
////Person* player_ptr = &player; // player_ptr points at a player
//
////    cout<<"Player name: "<< player.get_name()<<"\n";
////    cout<<"Player initial score: "<< player.get_score()<<"\n";
////
////    player.increment_score();
////
////    cout<<"Player new score: "<< player.get_score()<<"\n";
////
////
////    cout<< "Player char BEFORE nullptr: " << player_ptr->get_marker() << "\n";
////
////    //what happens if the player_ptr points to nullptr
////
////    player_ptr = nullptr;
////    player_ptr != nullptr? player_ptr;
////    cout<< "Player char AFTER nullptr: " << player_ptr->get_marker() << "\n";
