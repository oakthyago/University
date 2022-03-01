clc; clear all; close all
%Janela Retangular
N=512;
n=0:1:N-1;
x=sin(2*pi*4*(n/64))
stem(n,x);
pause;
%DFT Retangular
z=zeros(1,N);
y=sin(2*pi*4*(n/64));
for i=1:N
    for k=1:N
       z(i)=y(k)*(cos(2*pi*((i-1)*(k-1)/N))-1i*sin(2*pi*((i-1)*(k-1)/N)))+z(i); 
    end
end
m=abs(z);
stem(0:4:(N-1)*4, abs(z))
pause;

%Janela Triangular
x=sin(2*pi*4*(n/64))
%if n<N/2
  w1=2*n(1:N/2)/(N) 
%else
  w2=2-(2*(n(N/2+1:N))/(N))
%end
w = [w1 w2];
stem(n,w.*x);
pause;
%DFT Triangular
z=zeros(1,N);
y=w.*x;
for i=1:N
    for k=1:N
       z(i)=y(k)*(cos(2*pi*((i-1)*(k-1)/N))-1i*sin(2*pi*((i-1)*(k-1)/N)))+z(i); 
    end
end
m=abs(z);
stem(0:4:(N-1)*4, abs(z))
pause;

%Janela de Hamming
x=sin(2*pi*4*(n/64))
w=0.54-(0.46*cos(2*pi*(n/N)))
plot(n,w, n, -w, n, w.*x);
pause;
%DFT Hamming
z=zeros(1,N);
y=w.*x;
for i=1:N
    for k=1:N
       z(i)=y(k)*(cos(2*pi*((i-1)*(k-1)/N))-1i*sin(2*pi*((i-1)*(k-1)/N)))+z(i); 
    end
end
m=abs(z);
stem(0:4:(N-1)*4, abs(z))
pause;

%Janela de Hanning
x=sin(2*pi*4*(n/64))
w=0.5-(0.5*(cos(2*pi*(n/N))))
plot(n,w, n, -w, n, w.*x);
pause;
%DFT Hanning
z=zeros(1,N);
y=w.*x;
for i=1:N
    for k=1:N
       z(i)=y(k)*(cos(2*pi*((i-1)*(k-1)/N))-1i*sin(2*pi*((i-1)*(k-1)/N)))+z(i); 
    end
end
m=abs(z);
stem(0:4:(N-1)*4, abs(z))
pause;