Action()
{
	lr_start_transaction("UC_4_Find_and_Choose_Flight");
	lr_start_transaction("Gotosite");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

/*Correlation comment - Do not change!  Original value='129601.215147833zzzzDzcpfAtVzzzHDQQQipVHfAcf' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);
	web_reg_find("Fail=NotFound",
		"Text/DIG=A Session ID has been created and loaded into a cookie called MSO",
		LAST);
	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	lr_end_transaction("Gotosite",LR_AUTO);
	lr_start_transaction("login");
	
	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_reg_find("Fail=NotFound",
		"Text/DIG=User password was correct",
		LAST);
	web_reg_find("Text=Welcome, <b>{login}</b>",
		LAST);
	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t3.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=81", ENDITEM,
		"Name=login.y", "Value=14", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);


	lr_end_transaction("login",LR_AUTO);

	lr_start_transaction("click_flights");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(53);
	web_reg_find("Fail=NotFound",
		"Text/DIG=User has returned to the search page",
		LAST);
	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"http://localhost:1080");
	
	lr_end_transaction("click_flights", LR_AUTO);

	lr_start_transaction("fill_find_flights");

	lr_think_time(34);
	web_reg_find("Fail=NotFound",
		"Text/DIG=Flight departing from",
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Text/DIG=Flight departing from <B>{depart}</B> to <B>{arrive}</B> on <B>{departDate}</B>",
		LAST);
	
	web_reg_save_param_attrib(
		
	"ParamName=outboundFlight",
	"TagName=input",
	"Extract=value",
	"Name=outboundFlight",
//	"Ordinal=ALL",
	"Type=radio",
	SEARCH_FILTERS,
	"IgnoreRedirections=No",
	LAST);
	
	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={depart}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={arrive}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value={numPass}", ENDITEM, 
		//"Name=roundtrip", "Value=off", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=findFlights.x", "Value=22", ENDITEM, 
		"Name=findFlights.y", "Value=6", ENDITEM, 
		//"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("fill_find_flights",LR_AUTO);
//	lr_save_string(lr_eval_string("outboundFlight_{random_id}"),"outboundFlight_id");
	lr_start_transaction("choose_flight");
	
	web_reg_find("Fail=NotFound",
		"Text/DIG=Flight Reservation",
		LAST);
	
	web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=numPassengers", "Value={numPass}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=reserveFlights.x", "Value=74", ENDITEM,
		"Name=reserveFlights.y", "Value=4", ENDITEM,
		LAST);

	lr_end_transaction("choose_flight",LR_AUTO);

	lr_start_transaction("logout");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(24);
	web_reg_find("Fail=NotFound",
		"Text/DIG=A Session ID has been created and loaded into a cookie called MSO",
		LAST);
	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	lr_end_transaction("UC_4_Find_and_Choose_Flight",LR_AUTO);

	return 0;
}