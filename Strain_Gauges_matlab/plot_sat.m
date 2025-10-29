load("Loadcell_sat.mat")
% Extract signal and time data
signal = squeeze(data.Data);
time = squeeze(data.Time);

% Create a new figure to draw the plot on
figure;

% Plot the signal against time
plot(time, signal);

% Add labels and a title to make the plot informative
xlabel('Time [s]');      % Label for the x-axis
ylabel('Signal');    % Label for the y-axis
title('Signal Vs Time'); % Title of the plot

% Optional: Add a grid for easier reading
grid on;

% Optional: Customize line appearance (e.g., red dashed line with circle markers)
% plot(time, signal, '--ro', 'LineWidth', 1.5, 'MarkerSize', 4);