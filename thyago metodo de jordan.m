%IFPB, 13/10/11
%Método de Jacob;
clc, clear all, close all

epsilon= 1E-10;
kmax=150;
x1(1)=0;x2(1)=0;
k=1; TOL=1;

while (k<=kmax & TOL>epsilon)

   x1(k+1)=0.5*(3+x2(k));
   x2(k+1)=3-x1(k);
   
   TOL=max([abs(x1(k+1)-x1(k)) abs(x2(k+1)-x2(k))]);
   k=k+1;
end
disp([x1' x2']) 