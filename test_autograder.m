autograder_setup = struct('Q1','double','Q2','double','Q3','double','Q4','double','Q5','double','Q6','double','Q7','double','Q8','double','Q9','double','Q10','double');
export_workspace_var(autograder_setup,true,NaN);

w = -pi:pi/2000:pi;
%% part a
b1 = [0,0,0,1,0,0,0,0,0,0];
H1 = abs(freq_resp_me(b1,w));
export_workspace_var("Q1",false,abs(H1));
%% Part b
%length 10
for i = 1:1:10
    b2(i) = (8/9)^(i-1);
end
H2 = abs(freq_resp_me(b2,w));
export_workspace_var("Q2",false,abs(H2));

%length 100

for i = 1:1:100
    b3(i) = (8/9)^(i-1);
end
H3 = abs(freq_resp_me(b3,w));
export_workspace_var("Q3",false,abs(H3));
%% part c
%length 10
for i = 1:1:10
    b4(i) = (-8/9)^(i-1);
end
H4 = abs(freq_resp_me(b4,w));
export_workspace_var("Q4",false,abs(H4));


%length 100
for i = 1:1:100
    b5(i) = (-8/9)^(i-1);
end
H5 = abs(freq_resp_me(b5,w));
export_workspace_var("Q5",false,abs(H5));

%% part d
%length 10
for i = 1:1:10
    if(i < 6)
        b6(i) = 1;
    else
        b6(i) = 0;
    end
end
H6 = abs(freq_resp_me(b6,w));
export_workspace_var("Q6",false,abs(H6));

%length 100
for i = 1:1:10
    if(i < 6)
        b7(i) = 1;
    else
        b7(i) = 0;
    end
end
H7 = abs(freq_resp_me(b7,w));
export_workspace_var("Q7",false,abs(H7));

%% part e
%length 10
for i = 1:1:10
    b8(i) = cos((pi/4)*(i-1));
end
H8 = abs(freq_resp_me(b8,w));
export_workspace_var("Q8",false,abs(H8));
%length 100
for i = 1:1:100
    b9(i) = cos((pi/4)*(i-1));
end
H9 = abs(freq_resp_me(b9,w));
export_workspace_var("Q9",false,abs(H9));



%x1 = abs(freq_resp_me(b1,w));
%x2 = abs(freq_resp_me(b2,w));
%x3 = abs(freq_resp_me(b3,w));
%x4 = abs(freq_resp_me(b4,w));
%x5 = abs(freq_resp_me(b5,w));
figure(1)
[z,fs] = audioread("corrupted_wannabe.wav");
H_LAST = freq_resp_me(z,w);
%plot(w,abs(H_LAST))
%% Bottom section
impulse = ones(1,3);
impulse(2) = -2*cos(1.42314);
filtered = conv(z,impulse);
%impulse = ones(1,3);
%impulse(2) = -2*cos(0.424115);
%filtered = conv(filtered,impulse);
%audiowrite("partially_filtered.wav",filtered,fs)
figure(2)
H_LAST_FOR_REAL = freq_resp_me(filtered,w);
%plot(w,abs(H_LAST_FOR_REAL))
export_workspace_var("Q10",false,abs(H_LAST_FOR_REAL));

%freqz(b,1,length(w))
%export_workspace_var("Q1",false,x1);
%export_workspace_var("Q2",false,x2);
%export_workspace_var("Q3",false,x3);
%export_workspace_var("Q4",false,x4);
%export_workspace_var("Q5",false,x5);





function H = freq_resp_me(b,w)
    H = 0;
    for k = 0:1:length(b)-1
        H = H + b(k+1)*exp(-1j*w*k);
    end
end