% Load the .mat file
load('Homing_Squence.mat');

% Extract signal A, signal B, and the time vector
signal_A = squeeze(data{1}.Values.Data);
signal_B = squeeze(data{2}.Values.Data);
time = squeeze(data{1}.Values.Time);



% Find the indices for the time interval between 34 and 36 seconds
figure;

idx1 = find(time >= 0 & time <= 35);

% Plot signals using stairs() to create a square wave effect
stairs(time(idx1), signal_B(idx1), 'b-', 'LineWidth', 1.5); % Plot Signal A in blue
hold on; % Hold the current plot to add another line
stairs(time(idx1), signal_A(idx1), 'r-', 'LineWidth', 1.5); % Plot Signal B in red
hold off; % Release the plot

% Add title, labels, legend, and grid for clarity
title('Homing Sequence and Digital Input');
xlabel('Time (s)');
ylabel('Signal Amplitude');
legend('PC13_Input', 'Pulse');
grid on;