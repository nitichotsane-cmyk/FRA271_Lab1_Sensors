% Create a new figure window
figure;

% --- Subplots for Encoder_3_Rotary.mat (Time: 5s - 12s) ---

% Load the data from the Rotary encoder file
load('Encoder_3_Rotary_2.mat');

% Extract the necessary data from the loaded structure
time_rotary = squeeze(data{1}.Values.Time);
count2deg_rotary = squeeze(data{1}.Values.Data);
derivative_rotary = squeeze(data{2}.Values.Data);

% Find the indices corresponding to the time interval 5s to 12s
idx_rotary = find(time_rotary >= 29 & time_rotary <= 32);

% Subplot 1: Rotary Count2Deg vs. Time
subplot(2, 2, 1);
plot(time_rotary(idx_rotary), count2deg_rotary(idx_rotary), 'b-', 'LineWidth', 1.5);
title('Position in Roatry Encoder');
xlabel('Time (s)');
ylabel('Position (rad)');
grid on;

% Subplot 2: Rotary Derivative vs. Time
subplot(2, 2, 2);
plot(time_rotary(idx_rotary), derivative_rotary(idx_rotary), 'r-', 'LineWidth', 1.5);
title('Velocity in Roatry Encoder');
xlabel('Time (s)');
ylabel('Velocity (rad/s)');
grid on;

% --- Subplots for Encoder_3_AMT.mat (Time: 5s - 12s) ---

% Load the data from the AMT encoder file
load('Encoder_3_AMT_2.mat');

% Extract the necessary data from the loaded structure
time_amt = squeeze(data{1}.Values.Time);
count2deg_amt = squeeze(data{1}.Values.Data);
derivative_amt = squeeze(data{2}.Values.Data);

% Find the indices corresponding to the time interval 5s to 12s
idx_amt = find(time_amt >= 9 & time_amt <= 13);

% Subplot 3: AMT Count2Deg vs. Time
subplot(2, 2, 3);
plot(time_amt(idx_amt), count2deg_amt(idx_amt), 'b-', 'LineWidth', 1.5);
title('Position in AMT103 Encoder');
xlabel('Time (s)');
ylabel('Position (rad)');
grid on;

% Subplot 4: AMT Derivative vs. Time
subplot(2, 2, 4);
plot(time_amt(idx_amt), derivative_amt(idx_amt), 'r-', 'LineWidth', 1.5);
title('Velocity in AMT103 Encoder');
xlabel('Time (s)');
ylabel('Velocity (rad/s)');
grid on;