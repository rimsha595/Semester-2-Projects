import os
import time
import requests
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

# Initialize the Chrome driver
service = Service(ChromeDriverManager().install())
options = webdriver.ChromeOptions()

# Optionally, run in headless mode (no UI)
# options.add_argument("--headless")

driver = webdriver.Chrome(service=service, options=options)

# URL of the website to scrape
url = "https://www.zillow.com/homes/"

# Open the URL
driver.get(url)

# Wait for the page to fully load and the required elements to appear
WebDriverWait(driver, 30).until(EC.presence_of_element_located((By.TAG_NAME, 'body')))

# Optionally wait more time for dynamic content to load
time.sleep(10)

# Get the page source
html_content = driver.page_source

# Close the browser
driver.quit()

# Parse the HTML code using BeautifulSoup
soup = BeautifulSoup(html_content, 'html.parser')
print(soup.prettify())

# Step 4: Extract Images, Contents, Links, and Headings
images = []
contents = []
links = []
headings = []

# Extract images
for img in soup.find_all('img'):
    if img.has_attr('src'):
        images.append(img['src'])
        
# Extract text content
for p in soup.find_all('p'):
    contents.append(p.get_text(strip=True))
    
# Extract links
for a in soup.find_all('a'):
    if a.has_attr('href'):
        links.append(a['href'])
        
# Extract headings
for h in soup.find_all(['h1', 'h2', 'h3', 'h4', 'h5', 'h6']):
    headings.append(h.get_text(strip=True))
    
# Print all extracted data on the terminal
print("\nExtracted Images:")
for img in images:
    print(img)
    
print("\nExtracted Text Content:")
for content in contents:
    print(content)
    
print("\nExtracted Links:")
for link in links:
    print(link)
    
print("\nExtracted Headings:")
for heading in headings:
    print(heading)
    
# Step 5: Organize and Save Content into Files
directories = ['images', 'text', 'links', 'headings']
for directory in directories:
    if not os.path.exists(directory):
        os.makedirs(directory)
        
# Save images
for i, img_url in enumerate(images):
    try:
        img_response = requests.get(img_url)
        with open(f'images/{i}.jpg', 'wb') as f:
            f.write(img_response.content)
    except Exception as e:
        print(f"Error saving image {img_url}: {e}")
        
# Save text content
text_file_path = 'text/content.txt'
try:
    with open(text_file_path, 'w', encoding='utf-8') as f:
        for content in contents:
            f.write(content + '\n')
    print(f"Text content saved successfully to {text_file_path}")
except Exception as e:
    print(f"Error saving text content: {e}")
    
# Save links
links_file_path = 'links/links.txt'
try:
    with open(links_file_path, 'w', encoding='utf-8') as f:
        for link in links:
            f.write(link + '\n')
    print(f"Links saved successfully to {links_file_path}")
except Exception as e:
    print(f"Error saving links: {e}")
    
# Save headings
headings_file_path = 'headings/headings.txt'
try:
    with open(headings_file_path, 'w', encoding='utf-8') as f:
        for heading in headings:
            f.write(heading + '\n')
    print(f"Headings saved successfully to {headings_file_path}")
except Exception as e:
    print(f"Error saving headings: {e}")

# Step 6: Error Handling
try:
    # Web scraping code here
    pass
except requests.exceptions.RequestException as e:
    print(f"Error: {e}")
except Exception as e:
    print(f"Error: {e}")
