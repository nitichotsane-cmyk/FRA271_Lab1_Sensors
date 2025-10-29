load("Strain_ga_RT.mat")
% Extract signal and time data
signal = squeeze(data.Data);
time = squeeze(data.Time);

% Create a new figure to draw the plot on
figure;

% Plot the signal against time
plot(time, signal,'LineWidth', 1.5);

% Add labels and a title to make the plot informative
xlabel('Time [s]');      % Label for the x-axis
ylabel('Weight [Kg]');    % Label for the y-axis
title('Weight Vs Time'); % Title of the plot

% Optional: Add a grid for easier reading
grid on;

% Optional: Customize line appearance (e.g., red dashed line with circle markers)
% plot(time, signal, '--ro', 'LineWidth', 1.5, 'MarkerSize', 4);