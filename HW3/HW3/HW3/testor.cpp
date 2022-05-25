////
////  testor.cpp
////  HW3
////
////  Created by Lance Aquino on 5/1/22.
////
//
//#include "textfile.h"
//#include <fstream>
//#include <iostream>
//#include <string>
//#include <sstream>
//
//using namespace std;
//int main()
//{
//    Textfile file1 = Textfile("test_txt_file.txt");
//    Textfile file2 = Textfile("test_txt_file_2.txt");
//
//    std::string file1_name = file1.get_file_name();
//    cout<< file1_name<< " has "<< file1.get_num_of_chars() <<" characters\n";
//    cout<< file1_name<< " has "<< file1.get_num_of_words()<< " words\n";
//    cout<< file1_name<< " has "<< file1.get_num_of_lines()<< " lines\n";
//
//    std::string file2_name = file2.get_file_name();
//    cout<< file2_name<< " has "<< file1.get_num_of_chars() <<" characters\n";
//    cout<< file2_name<< " has "<< file1.get_num_of_words()<< " words\n";
//    cout<< file2_name<< " has "<< file1.get_num_of_lines()<< " lines\n";
//
//    if (file1 == file2)
//    {
//        cout<< "Same number of lines";
//    }
//    else if(file1 < file2)
//    {
//        cout<< file2.get_file_name() << " has more lines";
//    }
//
//    else {
//        cout<< file1.get_file_name() << " has more lines";
//    }
//
//    return 0;
//
//}
