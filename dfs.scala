/*val a=Array(Array(1,1,0),Array(1,1,0),Array(0,0,0));*/
/*var a=new Array[Array[Int]](3)(3);*/
import util.control.Breaks._
val r=scala.util.Random
println("enter the number of vertices");
val n=Console.readInt;
println(n);
val a=Array.ofDim[Int](n,n)
println("enter the values of adjacency matrix");
for(i<-0 until n; j<-0 until n){
	if(j>i) a(i)(j)=r.nextInt(2); else a(i)(j)=0 
	
	}

for(i<-0 until n;j<-0 until n){
	print(a(i)(j));
}	
a	
val reach=new Array[Int](n);

def dfs(v:Int){
	var i=0;	
	reach(v)=1;
	for(i<-0 until a.length){
		if(a(v)(i)!=0 && reach(i)==0){
			println(v+"->"+i);
			dfs(i);
			}
		}
	}
var i=1;
var j=1;
var count=0;
for(i<-0 until a.length){
	reach(i)=0
	}	
	
var temp=0;
for(i<-0 until n){
	if(a(i).contains(1)){
		temp=i;
		break;
		}
		}
dfs(temp);
println("");
for(i<-0 until a.length){
	if(reach(i)!=0) count=count+1;
}		
if(count==a.length) println("graph is connected") else println("graph is not connected")


				 

