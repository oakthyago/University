%IFPB, 13/10/11
%Método de Jacob;
clc, clear all, close all

epsilon= 1E-2;
kmax=10 ;
x1(1)=0;x2(1)=0;x3(1)=0;
k=1; TOL=1;

while (k<=kmax & TOL>epsilon)

    x1(k+1)=(1/6)*(11.33+x2(k)+x3(k));
    x2(k+1)=(1/6)*(32+x1(k+1)+x3(k));
    x3(k+1)=(-1/6)*(42+x1(k+1)+x2(k+1));
    

   
   TOL=max([abs(-x2(k)-6*x3(k)-42) abs(6*x1(k+1)-x3(k)-11.33) abs(-32-x1(k+1)+6*x2(k+1))]);
   k=k+1;
end
disp([x1' x2' x3']) 