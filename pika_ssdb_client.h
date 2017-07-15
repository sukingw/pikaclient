//
// pika_ssdb_client.h
//
// Created by Wangshujing on 12/7/17
//

#include <iostream>
#include <vector>
#include <string>
#include "hiredis/hiredis.h"
#include <sstream>
class Client {
public:
	// 构造函数
	Client();
	// 析构函数
	~Client();
	//-------------------------------------连接状态------------------------
	// 判断是否链接成功
	bool isok();
	//-------------------------------------命令执行状态--------------------
	// get 时是否存在key
	bool isexist();
	// --------------------------------------行为-------------------------
	// 获得数据库信息字符串
	void getstr();
	// 释放Reply
	void freeReply();
	// 连接数据库
	void connect(const char *ip, int &port);
	// EXPIRE
	void expire(const std::string &key, const std::string &expire_time);
	// SET
	void set(const std::string &key, const std::string &val);
	// DEL
	void del(const std::string &key);
	// GET
	void get( const std::string &key,std::string &val);
	// MGET
	void mget( const std::string &mgetcommand);     //这种情况下，如果key值本省没有空格是很好用的接口
	void mget( const std::vector<std::string> &key);
	// MSET
	void mset( const std::vector<std::string> &key, const std::vector<std::string> &val);
	// DATA---------------------------------数据----------------------
	redisContext *redis ;
	redisReply   *reply ;
private:
	
	
protected:

};
