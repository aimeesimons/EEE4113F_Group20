data = readtable('Test 6 32 Samples Rapid Changes.csv','PreserveVariableNames',true);
offset = 3130;

% Extract data from the second row onwards (ignoring the first row)
x1_data = data{200:end, 1}; % Assuming the data you need is in the first column of the table data
x2_data = data{200:end, 2};
x3_data = data{200:end, 3};
x4_data = data{200:end, 4};
time_data = data{200:end, 5}; % Assuming the time data is in the fifth column of the table data

% Initialize an empty array to store time values in seconds
time_seconds = zeros(size(time_data, 1), 1);

for i = 1:size(time_data, 1)
    % Extract the time string from the current row
    time_str = time_data{i};
    
    % Split the time string into its components
    time_components = strsplit(time_str, ':');
    
    % Extract minutes and seconds
    minutes_str = time_components{1};
    seconds_and_milliseconds_str = time_components{2};
    
    % Convert components to numerical values
    minutes_numeric = str2double(minutes_str);
    seconds_and_milliseconds_numeric = str2double(seconds_and_milliseconds_str);
    
    % Calculate total time in seconds
    time_numeric = minutes_numeric * 60 + seconds_and_milliseconds_numeric - offset;
    
    % Assign the time value in seconds to the array
    time_seconds(i) = time_numeric;
end

% Reshape data to row vectors
time_seconds = reshape(time_seconds, 1, []);
x1_data = reshape(x1_data, 1, []);
x2_data = reshape(x2_data, 1, []);
x3_data = reshape(x3_data, 1, []);
x4_data = reshape(x4_data, 1, []);

% Create a new figure window
figure;

% Plot the data
plot(time_seconds, x1_data);
hold on
plot(time_seconds, x2_data);
plot(time_seconds, x3_data);
plot(time_seconds, x4_data);

% Add labels and title
xlabel('Reaction Time (seconds)');
ylabel('Weight(g)');
title('Reaction time vs. Weight');

% Add legend to identify each line
legend('Average', 'Moving Average', 'Median','Exponential', 'Location', 'best'); % Adjust the location of the legend as needed

% Create separate boxplots with adjusted positions% Create separate boxplots with adjusted positions
figure;
positions = [1, 2, 3, 4];  % Positions for each boxplot

boxplot(x1_data, 'Positions', positions(1)); % Boxplot for x1_data
hold on;
boxplot(x2_data, 'Positions', positions(2)); % Boxplot for x2_data
hold on;
boxplot(x3_data, 'Positions', positions(3)); % Boxplot for x3_data
hold on 
boxplot(x4_data, 'Positions', positions(4)); % Boxplot for x3_data



% Add labels and title
xlabel('Data Sets');
ylabel('Values');
title('Boxplots of Data Sets');

% Set the same label for all boxplots
set(gca, 'XTickLabel', {'Average', 'Moving average', 'Median', 'Exponential MA'});

% Adjust x-axis limits and ticks
xlim([0.5, 4.5]);
xticks(positions);
