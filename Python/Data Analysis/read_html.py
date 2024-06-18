import pandas as pd

# Set display option to show all columns
pd.set_option("display.max_columns", None)
pd.set_option("display.max_colwidth", 80)
pd.set_option("display.width", 80)

# URL of the webpage containing the tables
url = "https://en.wikipedia.org/wiki/World_population"

# Attempt to read HTML tables from the URL
try:
    tables = pd.read_html(url)
    print("Tables successfully read from the URL.")
except ValueError as e:
    print(f"Error reading the tables: {e}")
    tables = []

# Check if the tables list is not empty
if tables:
    # Access specific tables based on their positions
    try:
        world_population_milestones = tables[1]
        print("World Population Milestones Table:")
        print(world_population_milestones.head())
    except IndexError:
        print("The World Population Milestones table is not available.")

    try:
        population = tables[3]
        print("\nPopulation Table:")
        print(population.head())
    except IndexError:
        print("The Population table is not available.")
else:
    print("No tables were found on the provided URL.")
