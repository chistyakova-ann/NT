package ru.appline;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Map;
import java.util.concurrent.atomic.AtomicInteger;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonObject;

import logic.Model;
import logic.User;
@WebServlet(urlPatterns="/put")
public class Servletput extends HttpServlet {
//private AtomicInteger counter=new AtomicInteger(4);

Model model =Model.getInstance();


Gson gson=new GsonBuilder().setPrettyPrinting().create();
 
/*protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
	response.setContentType("text/html;charset=utf-8");
	request.setCharacterEncoding("UTF-8");
	PrintWriter pw=response.getWriter();
	int id=Integer.parseInt(request.getParameter("id"));
	String name=request.getParameter("name");
	String surname=request.getParameter("surname");
	String salary=request.getParameter("salary");
	if(id==0) {pw.print("<html>"+"<h3>Avaliable users:</h3><br/>"+
			"Id User: "+"<ul>");
	for (Map.Entry<Integer, User> entry : model.getFromList().entrySet()) {
		pw.print("<li>"+ entry.getKey()+"</li>"+"<ul>"+
	"<li>Name: "+entry.getValue().getName()+"</li>"+
	"<li>Surname: "+entry.getValue().getSurname()+"</li>"+
	"<li>Salary: "+entry.getValue().getSalary()+"</li>"+
			"</ul>");}
	pw.print("</ul>"+"<a href=\"update.jsp\">Update</a>"+"</html>");
	}else if(id>0) {if(id>model.getFromList().size()) {
		pw.print("<html>"+"<h3>Not this user</h3>"+
				"<a href=\"update.jsp\">Update</a>"+"</html>");}

	else {
	model.getFromList().get(id).setName(name);
	model.getFromList().get(id).setSurname(surname);
	model.getFromList().get(id).setSalary(salary);
	pw.print("<html>"+"<h3>User "+name+" "+surname+" "+"with salary "+salary+" update"+"<br/>"
			+"<a href=\"index.jsp\">Home</a>"+"</html>");
}
	}
	else { pw.print("<html>"+"<h3>id must be > 0</h3>"+
			"<a href=\"update.jsp\">Update</a>"+"</html>"+
			"<a href=\"index.jsp\">Home</a>"+"</html>");}
	}*/
protected void doPut(HttpServletRequest request, HttpServletResponse response) throws IOException {
	StringBuffer jb= new StringBuffer();
	String line;
	try {
		BufferedReader reader= request.getReader();
		while ((line=reader.readLine())!=null) {
			jb.append(line);
		}
	}catch(Exception e) {
		System.out.println("Error");
	}
	JsonObject jobj=gson.fromJson(String.valueOf(jb),JsonObject.class);
	request.setCharacterEncoding("UTF-8");
	int id=jobj.get("id").getAsInt();
/*	String name=jobj.get("name").getAsString();
	String surname=jobj.get("surname").getAsString();
	String salary=jobj.get("salary").getAsString();*/
	PrintWriter pw=response.getWriter();
	response.setContentType("application/json;charset=utf-8");

	if(id==0) {pw.print(gson.toJson(model.getFromList()));}
	else if(id<0) {pw.print(gson.toJson("id must be more than 0"));}
	else if(id>0) {
		if(id>model.getFromList().size()) {pw.print(gson.toJson("Not this user"));}
		else {
			String name=jobj.get("name").getAsString();
			String surname=jobj.get("surname").getAsString();
			String salary=jobj.get("salary").getAsString();
			model.getFromList().get(id).setName(name);
			model.getFromList().get(id).setSurname(surname);
			model.getFromList().get(id).setSalary(salary);
			pw.print(gson.toJson(model.getFromList().get(id)));}
		}
	}
}




