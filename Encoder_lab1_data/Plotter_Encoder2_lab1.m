% Load the .mat file
load('Encoder_1_1_R.mat');

% Extract the time vector (assuming it's the same for all signals)
% and the data for each signal
time = squeeze(data{1}.Values.Time);
signal_1 = squeeze(data{1}.Values.Data);
signal_2 = squeeze(data{2}.Values.Data);
signal_3 = squeeze(data{3}.Values.Data);

% Create a new figure window
figure;

% Plot all three signals on the same axes
plot(time, signal_1, 'b-', 'LineWidth', 1.5); % Signal 1 in blue
hold on; % Hold the current plot to add more lines
plot(time, signal_2, 'r-', 'LineWidth', 1.5); % Signal 2 in red
plot(time, signal_3, 'g-', 'LineWidth', 1.5); % Signal 3 in green
hold off; % Release the plot

% Add title, labels, a legend, and a grid for clarity
    title('Encoder Signals (X1, X2, X4)', 'FontSize', 14);
    xlabel('Time (seconds)', 'FontSize', 12);
    ylabel('Encoder Value', 'FontSize', 12);
    legend('Encoder X4', 'Encoder X2', 'Encoder X1');
grid on;