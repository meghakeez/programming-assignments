# Data Structures
This project analyzes 24 hours of Fitbit activity data from `FitbitData.csv`. It filters, dedupes, cleans, parses, and computes summary statistics using C structs, arrays, and file I/O.

## Features
- **Data Filtering:** Keep only records for the target patient  
- **Deduping:** Remove duplicate entries based on patient ID and minute  
- **Data Cleansing:** Replace missing fields with placeholder values  
- **Parsing:** Convert strings to numerical types and store in a struct array  
- **Summary Calculations:**  
  - Total calories  
  - Total distance  
  - Total floors  
  - Total steps  
  - Average heartrate  
  - Max steps in one minute  
  - Longest consecutive range of poor sleep  
- **Output:** Write results and cleaned data to `Results.csv`

## Data Structures
- `FitbitData` struct storing patient info, activity metrics, and sleep level  
- `Sleep` enum representing sleep states  
- Array of **1440** `FitbitData` records (one per minute)
