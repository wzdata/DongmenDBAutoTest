
#include "stdio.h"
#include "mysql.h"

#include <string>

#include <iostream>
#include <mysqlconn_manager.h>

using namespace std;

int test_mysqlconn_manager(){
    MySQLConnManager conn;
    cout<<conn.init("127.0.0.1", "root", "123456", "mysql", 3366, "utf8")<<endl;
    cout<<conn.reconnect()<<endl;
    cout<<conn.get_error_msg()<<endl;
    vector<vector<string> > v;
    cout<<conn.select_data("select * from user", v)<<endl;
    for(size_t i = 0 ; i < v.size(); i++)
    {
        for(size_t j = 0; j < v[i].size(); j++)
            cout<<v[i][j]<<endl;
        cout<<"---------------"<<endl;
    }
    cout<<conn.get_error_msg()<<endl;
    return 0;
}

int test_mysql_conn_c(){
    MYSQL * con; //= mysql_init((MYSQL*) 0);
    MYSQL_RES *res;
    MYSQL_ROW row;
    char tmp[400];
    //database configuartion
    char dbuser[30] = "root";//mysql账号名
    char dbpasswd[30] = "123456"; //mysql账号密码
    char dbip[30] = "localhost";
    char dbname[50] = "mysql";//数据库名
    char tablename[50] = "user";//数据表名
    unsigned int port = 3306;
    char *query = NULL;

    int x;
    int y;
    int rt;//return value
    unsigned int t;

    int count = 0;

    con = mysql_init((MYSQL*)0);

    if (con != NULL && mysql_real_connect(con, dbip, dbuser, dbpasswd, dbname, port, NULL, 0)) {
        if (!mysql_select_db(con, dbname)) {
            printf("Select successfully the database!\n");
            con->reconnect = 1;
            query = "set names \'GBK\'";
            rt = mysql_real_query(con, query, strlen(query));
            if (rt) {
                printf("Error making query: %s !!!\n", mysql_error(con));
            }
            else {
                printf("query %s succeed!\n", query);
            }
        }
    }
    else {
        MessageBoxW(NULL, L"无法连接数据库,请检查连接配置!", L"", NULL);

        exit(0);
    }

    //sprintf(tmp, "insert into %s values(%s,%d,%d)", tablename, "null", x, y); //注意如何向具有自增字段的数据库中插入记录
    sprintf(tmp, "insert into bl values(null,'x','x','x','x')");


    rt = mysql_real_query(con, tmp, strlen(tmp));
    if (rt)
    {
        printf("Error making query: %s !!!\n", mysql_error(con));
    }
    else
    {
        printf("%s executed!!!\n", tmp);
    }

    sprintf(tmp, "select * from %s", tablename);
    rt = mysql_real_query(con, tmp, strlen(tmp));
    if (rt)
    {
        printf("Error making query: %s !!!\n", mysql_error(con));
    }
    else
    {
        printf("%s executed!!!\n", tmp);
    }
    res = mysql_store_result(con);//将结果保存在res结构体中

    while (row = mysql_fetch_row(res)) {
        for (t = 0; t<mysql_num_fields(res); t++) {
            printf("%s  ", row[t]);
        }
        printf(".............\n");
        count++;
    }

    printf("number of rows %d\n", count);
    printf("mysql_free_result...\n");
    mysql_free_result(res);
    mysql_close(con);
    return 0;
}
int main()
{
    test_mysqlconn_manager();
}