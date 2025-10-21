% Load the .mat file
load('Encoder_2_CCW-CW.mat');

% Extract signal A, signal B, and the time vector
signal_A = squeeze(data{1}.Values.Data);
signal_B = squeeze(data{2}.Values.Data);
time = squeeze(data{1}.Values.Time);

% --- Subplot 1: Time from 34 to 36 seconds ---

% Create the first subplot in a 2x1 grid
subplot(2, 1, 1);

% Find the indices for the time interval between 34 and 36 seconds
idx1 = find(time >= 34 & time <= 36);

% Plot signals using stairs() to create a square wave effect
stairs(time(idx1), signal_A(idx1), 'b-', 'LineWidth', 1.5); % Plot Signal A in blue
hold on; % Hold the current plot to add another line
stairs(time(idx1), signal_B(idx1), 'r-', 'LineWidth', 1.5); % Plot Signal B in red
hold off; % Release the plot

% Add title, labels, legend, and grid for clarity
title('Signals A & B When CCW');
xlabel('Time (s)');
ylabel('Signal Amplitude');
legend('Signal A', 'Signal B');
grid on;
ylim([-2 1.5]); % Adjust y-axis for better visibility

% --- Subplot 2: Time from 41 to 46 seconds ---

% Create the second subplot in the 2x1 grid
subplot(2, 1, 2);

% Find the indices for the time interval between 41 and 46 seconds
idx2 = find(time >= 41 & time <= 46);

% Plot signals using stairs()
stairs(time(idx2), signal_A(idx2), 'b-', 'LineWidth', 1.5); % Plot Signal A in blue
hold on; % Hold the current plot
stairs(time(idx2), signal_B(idx2), 'r-', 'LineWidth', 1.5); % Plot Signal B in red
hold off; % Release the plot

% Add title, labels, legend, and grid for clarity
title('Signals A & B When CW');
xlabel('Time (s)');
ylabel('Signal Amplitude');
legend('Signal A', 'Signal B');
grid on;
ylim([-2 1.5]); % Adjust y-axis for better visibility