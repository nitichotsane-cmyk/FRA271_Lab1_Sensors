% โหลดข้อมูลจากไฟล์
load('Hall_sensor_value2.mat');  

% ดึงข้อมูลจาก test.data
signal = squeeze(noise_sample{1}.Values.Data);   % แปลงจาก 1x1xN → Nx1

% ตรวจสอบขนาดข้อมูล
N = length(signal);

% สมมติ sampling frequency (Hz)
Fs = 1/0.2;  % ← ปรับค่าตามความจริง

% ทำ Fourier Transform
Y = fft(double(signal));   % แปลงเป็น double ก่อนทำ FFT

% คำนวณขนาดและแกนความถี่
P2 = abs(Y/N);          
P1 = P2(1:N/2+1);       
P1(2:end-1) = 2*P1(2:end-1);

f = Fs*(0:(N/2))/N;     

% แสดงกราฟ
figure;
plot(f, P1, 'LineWidth', 1.5);
xlabel('Frequency (Hz)');
ylabel('Amplitude');
title('Single-Sided Amplitude Spectrum of test.data');
grid on;
