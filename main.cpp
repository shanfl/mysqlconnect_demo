#include "MySqlConnect.hpp"

int main(){
	//MysqlInit::init();

	MysqlConnect con("123.103.127.23", "hisense", "HisenseA6F5", "remote-dev", "utf8mb4", 8007);
	bool b = con.Connect();

	if (b) {
		DBProc proc(&con);
		int suc = proc.Query("set @result = 1 ;show TABLES;show databases;select * from d01_message limit 10;") == 0;
		if (suc) {
			auto&result = proc.GetResult()->GetMultiResTable();
			//auto n = result->RowCount();
			std::cout << "result.size():" << result.size();

			for (auto &it : result) {
				it.info_print();
			}
		}



		con.Disconnect();
	}

	return 1;
}


/*

if (mysql_query(&mysql, "call sp_test()") == 0)
{
	do
	{
		if (mysql_field_count(&mysql) > 0)
		{
		rs = mysql_store_result(&mysql);
		mysql_free_result(rs);
		}
	}
	while (mysql_next_result(&mysql) == 0);
}
————————————————
版权声明：本文为CSDN博主「luoti784600」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/luoti784600/article/details/21532279
*/
