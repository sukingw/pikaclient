//
//  main.cpp
//  ssdb-test
//
//  Created by wangshujing on 13/07/17 BE.
//  Copyright © 2559 BE wang shujing. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <pika_ssdb_client.h>
#include "pika_ssdb_test.h"
int main(int argc, const char** argv) {
    //const char* command = argv[1];
    //const char* filepath = argv[2];
    /*if(command == NULL || filepath == NULL) {
        printf("usage : ./ssdb-benchmark [mset|msettest|mget|delete|expire] [movie_file_path]\n");
        printf("mget env : SSDB_PORT(default 9221) | MGET_AMOUNT(default 7000000) | MGET_SIZE(default 100) | DEL_AMOUNT(default 7000000) | EXPIRE_AMOUNT(default 7000000)\n");
        exit(0);
    }*/
    const char *ip = "127.0.0.1";
    int port =9221 ;
    int mget_amount =7000000;// 7000000;
    int mget_size = 10;
    int del_amount = 70000;
    int expire_amount = 70000;

	const char *filepath = "./data.txt";
	Client *client = new Client();				
	client->connect(ip,port);
	if(!client->isok()){
		printf("Connect to pikaServer Faile!\n");
		delete client;
		return -1;
	}
	
	std::cout<<"Connect to pikaServer Success!"<< std::endl;
	//test for mset
	test_multi_set(client, filepath);                	 
	// test for set and correct rate 
	//test_set(client,filepath);  				 
	// test for get
	//test_get(client,filepath,mget_amount,mget_size);  	
	// test for mget
	test_multi_get(client,filepath,mget_amount,mget_size);   
	// test for delete
	//test_delete(client,filepath,del_amount);                 
	// test for expire
	//test_multi_expire(client,filepath,expire_amount);          
	// test for status
	test_status(client);

	delete client;
	std::cout<<"Disconnect from the pikaServer, goodbye!"<< std::endl;
    	return 0;
}
