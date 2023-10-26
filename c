{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": 1,
   "id": "f3d18d68",
   "metadata": {},
   "outputs": [],
   "source": [
    "import numpy as np\n",
    "import pandas as pd\n",
    "import seaborn as sns\n",
    "import matplotlib.pyplot as plt\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 2,
   "id": "1c0a22eb",
   "metadata": {},
   "outputs": [],
   "source": [
    "df = pd.read_csv('laptop_data.csv')"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 3,
   "id": "d748587d",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<style scoped>\n",
       "    .dataframe tbody tr th:only-of-type {\n",
       "        vertical-align: middle;\n",
       "    }\n",
       "\n",
       "    .dataframe tbody tr th {\n",
       "        vertical-align: top;\n",
       "    }\n",
       "\n",
       "    .dataframe thead th {\n",
       "        text-align: right;\n",
       "    }\n",
       "</style>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>Id</th>\n",
       "      <th>Company</th>\n",
       "      <th>TypeName</th>\n",
       "      <th>Inches</th>\n",
       "      <th>ScreenResolution</th>\n",
       "      <th>Cpu</th>\n",
       "      <th>Ram</th>\n",
       "      <th>Memory</th>\n",
       "      <th>Gpu</th>\n",
       "      <th>OpSys</th>\n",
       "      <th>Weight</th>\n",
       "      <th>Price</th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>0</th>\n",
       "      <td>1</td>\n",
       "      <td>Apple</td>\n",
       "      <td>Ultrabook</td>\n",
       "      <td>13.3</td>\n",
       "      <td>IPS Panel Retina Display 2560x1600</td>\n",
       "      <td>Intel Core i5 2.3GHz</td>\n",
       "      <td>8GB</td>\n",
       "      <td>128GB SSD</td>\n",
       "      <td>Intel Iris Plus Graphics 640</td>\n",
       "      <td>macOS</td>\n",
       "      <td>1.37kg</td>\n",
       "      <td>71378.6832</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1</th>\n",
       "      <td>2</td>\n",
       "      <td>Apple</td>\n",
       "      <td>Ultrabook</td>\n",
       "      <td>13.3</td>\n",
       "      <td>1440x900</td>\n",
       "      <td>Intel Core i5 1.8GHz</td>\n",
       "      <td>8GB</td>\n",
       "      <td>128GB Flash Storage</td>\n",
       "      <td>Intel HD Graphics 6000</td>\n",
       "      <td>macOS</td>\n",
       "      <td>1.34kg</td>\n",
       "      <td>47895.5232</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>2</th>\n",
       "      <td>3</td>\n",
       "      <td>HP</td>\n",
       "      <td>Notebook</td>\n",
       "      <td>15.6</td>\n",
       "      <td>Full HD 1920x1080</td>\n",
       "      <td>Intel Core i5 7200U 2.5GHz</td>\n",
       "      <td>8GB</td>\n",
       "      <td>256GB SSD</td>\n",
       "      <td>Intel HD Graphics 620</td>\n",
       "      <td>No OS</td>\n",
       "      <td>1.86kg</td>\n",
       "      <td>30636.0000</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>3</th>\n",
       "      <td>4</td>\n",
       "      <td>Apple</td>\n",
       "      <td>Ultrabook</td>\n",
       "      <td>15.4</td>\n",
       "      <td>IPS Panel Retina Display 2880x1800</td>\n",
       "      <td>Intel Core i7 2.7GHz</td>\n",
       "      <td>16GB</td>\n",
       "      <td>512GB SSD</td>\n",
       "      <td>AMD Radeon Pro 455</td>\n",
       "      <td>macOS</td>\n",
       "      <td>1.83kg</td>\n",
       "      <td>135195.3360</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>4</th>\n",
       "      <td>5</td>\n",
       "      <td>Apple</td>\n",
       "      <td>Ultrabook</td>\n",
       "      <td>13.3</td>\n",
       "      <td>IPS Panel Retina Display 2560x1600</td>\n",
       "      <td>Intel Core i5 3.1GHz</td>\n",
       "      <td>8GB</td>\n",
       "      <td>256GB SSD</td>\n",
       "      <td>Intel Iris Plus Graphics 650</td>\n",
       "      <td>macOS</td>\n",
       "      <td>1.37kg</td>\n",
       "      <td>96095.8080</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>...</th>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1298</th>\n",
       "      <td>1299</td>\n",
       "      <td>Lenovo</td>\n",
       "      <td>2 in 1 Convertible</td>\n",
       "      <td>14.0</td>\n",
       "      <td>IPS Panel Full HD / Touchscreen 1920x1080</td>\n",
       "      <td>Intel Core i7 6500U 2.5GHz</td>\n",
       "      <td>4GB</td>\n",
       "      <td>128GB SSD</td>\n",
       "      <td>Intel HD Graphics 520</td>\n",
       "      <td>Windows 10</td>\n",
       "      <td>1.8kg</td>\n",
       "      <td>33992.6400</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1299</th>\n",
       "      <td>1300</td>\n",
       "      <td>Lenovo</td>\n",
       "      <td>2 in 1 Convertible</td>\n",
       "      <td>13.3</td>\n",
       "      <td>IPS Panel Quad HD+ / Touchscreen 3200x1800</td>\n",
       "      <td>Intel Core i7 6500U 2.5GHz</td>\n",
       "      <td>16GB</td>\n",
       "      <td>512GB SSD</td>\n",
       "      <td>Intel HD Graphics 520</td>\n",
       "      <td>Windows 10</td>\n",
       "      <td>1.3kg</td>\n",
       "      <td>79866.7200</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1300</th>\n",
       "      <td>1301</td>\n",
       "      <td>Lenovo</td>\n",
       "      <td>Notebook</td>\n",
       "      <td>14.0</td>\n",
       "      <td>1366x768</td>\n",
       "      <td>Intel Celeron Dual Core N3050 1.6GHz</td>\n",
       "      <td>2GB</td>\n",
       "      <td>64GB Flash Storage</td>\n",
       "      <td>Intel HD Graphics</td>\n",
       "      <td>Windows 10</td>\n",
       "      <td>1.5kg</td>\n",
       "      <td>12201.1200</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1301</th>\n",
       "      <td>1302</td>\n",
       "      <td>HP</td>\n",
       "      <td>Notebook</td>\n",
       "      <td>15.6</td>\n",
       "      <td>1366x768</td>\n",
       "      <td>Intel Core i7 6500U 2.5GHz</td>\n",
       "      <td>6GB</td>\n",
       "      <td>1TB HDD</td>\n",
       "      <td>AMD Radeon R5 M330</td>\n",
       "      <td>Windows 10</td>\n",
       "      <td>2.19kg</td>\n",
       "      <td>40705.9200</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1302</th>\n",
       "      <td>1303</td>\n",
       "      <td>Asus</td>\n",
       "      <td>Notebook</td>\n",
       "      <td>15.6</td>\n",
       "      <td>1366x768</td>\n",
       "      <td>Intel Celeron Dual Core N3050 1.6GHz</td>\n",
       "      <td>4GB</td>\n",
       "      <td>500GB HDD</td>\n",
       "      <td>Intel HD Graphics</td>\n",
       "      <td>Windows 10</td>\n",
       "      <td>2.2kg</td>\n",
       "      <td>19660.3200</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "<p>1303 rows × 12 columns</p>\n",
       "</div>"
      ],
      "text/plain": [
       "        Id Company            TypeName  Inches  \\\n",
       "0        1   Apple           Ultrabook    13.3   \n",
       "1        2   Apple           Ultrabook    13.3   \n",
       "2        3      HP            Notebook    15.6   \n",
       "3        4   Apple           Ultrabook    15.4   \n",
       "4        5   Apple           Ultrabook    13.3   \n",
       "...    ...     ...                 ...     ...   \n",
       "1298  1299  Lenovo  2 in 1 Convertible    14.0   \n",
       "1299  1300  Lenovo  2 in 1 Convertible    13.3   \n",
       "1300  1301  Lenovo            Notebook    14.0   \n",
       "1301  1302      HP            Notebook    15.6   \n",
       "1302  1303    Asus            Notebook    15.6   \n",
       "\n",
       "                                ScreenResolution  \\\n",
       "0             IPS Panel Retina Display 2560x1600   \n",
       "1                                       1440x900   \n",
       "2                              Full HD 1920x1080   \n",
       "3             IPS Panel Retina Display 2880x1800   \n",
       "4             IPS Panel Retina Display 2560x1600   \n",
       "...                                          ...   \n",
       "1298   IPS Panel Full HD / Touchscreen 1920x1080   \n",
       "1299  IPS Panel Quad HD+ / Touchscreen 3200x1800   \n",
       "1300                                    1366x768   \n",
       "1301                                    1366x768   \n",
       "1302                                    1366x768   \n",
       "\n",
       "                                       Cpu   Ram               Memory  \\\n",
       "0                     Intel Core i5 2.3GHz   8GB            128GB SSD   \n",
       "1                     Intel Core i5 1.8GHz   8GB  128GB Flash Storage   \n",
       "2               Intel Core i5 7200U 2.5GHz   8GB            256GB SSD   \n",
       "3                     Intel Core i7 2.7GHz  16GB            512GB SSD   \n",
       "4                     Intel Core i5 3.1GHz   8GB            256GB SSD   \n",
       "...                                    ...   ...                  ...   \n",
       "1298            Intel Core i7 6500U 2.5GHz   4GB            128GB SSD   \n",
       "1299            Intel Core i7 6500U 2.5GHz  16GB            512GB SSD   \n",
       "1300  Intel Celeron Dual Core N3050 1.6GHz   2GB   64GB Flash Storage   \n",
       "1301            Intel Core i7 6500U 2.5GHz   6GB              1TB HDD   \n",
       "1302  Intel Celeron Dual Core N3050 1.6GHz   4GB            500GB HDD   \n",
       "\n",
       "                               Gpu       OpSys  Weight        Price  \n",
       "0     Intel Iris Plus Graphics 640       macOS  1.37kg   71378.6832  \n",
       "1           Intel HD Graphics 6000       macOS  1.34kg   47895.5232  \n",
       "2            Intel HD Graphics 620       No OS  1.86kg   30636.0000  \n",
       "3               AMD Radeon Pro 455       macOS  1.83kg  135195.3360  \n",
       "4     Intel Iris Plus Graphics 650       macOS  1.37kg   96095.8080  \n",
       "...                            ...         ...     ...          ...  \n",
       "1298         Intel HD Graphics 520  Windows 10   1.8kg   33992.6400  \n",
       "1299         Intel HD Graphics 520  Windows 10   1.3kg   79866.7200  \n",
       "1300             Intel HD Graphics  Windows 10   1.5kg   12201.1200  \n",
       "1301            AMD Radeon R5 M330  Windows 10  2.19kg   40705.9200  \n",
       "1302             Intel HD Graphics  Windows 10   2.2kg   19660.3200  \n",
       "\n",
       "[1303 rows x 12 columns]"
      ]
     },
     "execution_count": 3,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "df\n",
    "# df.drop(columns='Unnamed: 0',inplace=True)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 4,
   "id": "a5948ef3",
   "metadata": {},
   "outputs": [],
   "source": [
    "df['Ram']=df['Ram'].str.replace('GB','').astype(int)\n",
    "df['Weight']=df['Weight'].str.replace('kg','').astype(float)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 5,
   "id": "c14ff78d",
   "metadata": {},
   "outputs": [],
   "source": [
    "# sns.distplot(df['Price'])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 6,
   "id": "da316e02",
   "metadata": {},
   "outputs": [],
   "source": [
    "# df['Company'].value_counts().plot(kind='bar')"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 7,
   "id": "e6ed26f6",
   "metadata": {},
   "outputs": [],
   "source": [
    "# sns.barplot(x=df['Company'],y=df['Price'])\n",
    "# plt.xticks(rotation='vertical')\n",
    "# plt.show()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 8,
   "id": "5ddacce5",
   "metadata": {},
   "outputs": [],
   "source": [
    "# df['TypeName'].value_counts().plot(kind='bar')"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 9,
   "id": "f7d32037",
   "metadata": {},
   "outputs": [],
   "source": [
    "# sns.barplot(df['TypeName'],df['Price'])\n",
    "# plt.xticks(rotation='vertical')\n",
    "# plt.show()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 10,
   "id": "e498c16d",
   "metadata": {},
   "outputs": [],
   "source": [
    "# sns.distplot(df['Inches'])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 11,
   "id": "2088f54c",
   "metadata": {},
   "outputs": [],
   "source": [
    "# sns.scatterplot(x=df['Inches'],y=df['Price'])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 12,
   "id": "3b21f8b8",
   "metadata": {},
   "outputs": [],
   "source": [
    "# df['ScreenResolution'].value_counts()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 13,
   "id": "55ebde11",
   "metadata": {},
   "outputs": [],
   "source": [
    "df['TouchScreen']=df['ScreenResolution'].apply(lambda x:1 if 'Touchscreen' in x else 0)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 14,
   "id": "0a68cc6f",
   "metadata": {},
   "outputs": [],
   "source": [
    "# df['TouchScreen'].value_counts().plot(kind='bar')"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 15,
   "id": "114f8855",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "<Axes: xlabel='TouchScreen', ylabel='Price'>"
      ]
     },
     "execution_count": 15,
     "metadata": {},
     "output_type": "execute_result"
    },
    {
     "data": {
      "image/png": "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S9kLAABAk3VRZ5ree+895efnNxrPz8/X+++//5ObAgAAaGouKjRNnTpVdXV1jcbdbremTp36k5sCAABoai4qNB04cEDR0dGNxrt06aKDBw/+5KYAAACamosKTTabTV988UWj8YMHDyooKOgnNwUAANDUXFRoGjRokCZMmOBx9++DBw/qySef1G9+85tL1hwAAEBTcVGhKSMjQ0FBQerSpYuioqIUFRWlrl27qm3btnrllVcudY8AAABed1G3HLDZbNqyZYsKCgq0a9cuBQYGqnv37rrzzjsvdX8AAABNwkXfp8lisWjAgAEaMGDApewHAACgSTIdmhYuXKjRo0crICBACxcu/MHaxx9//Cc3BgAA0JSYDk3z5s3T8OHDFRAQoHnz5n1vncViITQBAICrjunQdOjQofP+GwAA4Ofggn89d/bsWV1//fXat2/f5egHAACgSbrg0NSyZUudOXPmcvQCAADQZF3UfZpSUlL08ssvq7a29lL3AwAA0CRd1C0Htm/frsLCQq1bt07dunVr9KdT/vrXv16S5gAAAJqKiwpNISEhSkxMvNS9AAAANFkXFJrq6+s1e/ZsffbZZ6qpqdHdd9+t6dOnKzAw8HL1BwAA0CRc0DVNM2fO1NNPP63g4GD94he/0MKFC5WSknJJGnnppZdksVg0YcIEY+zMmTNKSUlR27ZtFRwcrMTERJWXl3s8r6ysTAkJCWrVqpVCQ0M1adKkRtdabdiwQT179pS/v786d+6srKysRvtfvHixOnXqpICAAMXFxWnbtm2X5HUBAICrwwWFpjfeeENLlixRfn6+1q5dq3fffVdvvfWW6uvrf1IT27dv13//93+re/fuHuMTJ07Uu+++q9WrV2vjxo06cuSIHnjgAWO+rq5OCQkJqqmp0ZYtW7RixQplZWUpPT3dqDl06JASEhLUr18/lZSUaMKECXrssceUn59v1GRnZys1NVXTpk3Tzp071aNHDzkcDh09evQnvS4AAHD1uKDQVFZWpnvvvdd4HB8fL4vFoiNHjlx0A6dPn9bw4cP12muv6ZprrjHGKysr9frrr2vu3Lm6++67FRsbq+XLl2vLli366KOPJEnr1q3Tp59+qjfffFMxMTEaOHCgnn/+eS1evFg1NTWSpMzMTEVFRWnOnDnq2rWrxo0bpwcffNDjruZz587VqFGjNGLECEVHRysz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",
      "text/plain": [
       "<Figure size 640x480 with 1 Axes>"
      ]
     },
     "metadata": {},
     "output_type": "display_data"
    }
   ],
   "source": [
    "sns.barplot(x=df['TouchScreen'],y=df['Price'])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 16,
   "id": "3a5727a5",
   "metadata": {},
   "outputs": [],
   "source": [
    "df['IPS']=df['ScreenResolution'].apply(lambda x:1 if 'IPS' in x else 0)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 17,
   "id": "1a672454",
   "metadata": {},
   "outputs": [],
   "source": [
    "# df['IPS'].value_counts().plot(kind='bar')"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 18,
   "id": "d42f5d46",
   "metadata": {},
   "outputs": [],
   "source": [
    "# sns.barplot(x=df['IPS'],y=df['Price'])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 19,
   "id": "0bb82bac",
   "metadata": {},
   "outputs": [],
   "source": [
    "new = df['ScreenResolution'].str.split('x',expand=True,n=1)\n",
    "df['X_res']=new[0]\n",
    "df['Y_res']=new[1].astype(int)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 20,
   "id": "51053fcf",
   "metadata": {},
   "outputs": [],
   "source": [
    "df['X_res']=df['X_res'].apply(lambda x:x.split()[-1]).astype(int)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 21,
   "id": "c4c685e5",
   "metadata": {},
   "outputs": [],
   "source": [
    "# df.corr()['Price']"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 22,
   "id": "f296a680",
   "metadata": {},
   "outputs": [],
   "source": [
    "df['ppi']=((df['X_res']**2 + df['Y_res']**2)**0.5/df['Inches']).astype(float)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 23,
   "id": "ac06e960",
   "metadata": {},
   "outputs": [],
   "source": [
    "df.drop(columns=['ScreenResolution','Inches','X_res','Y_res'],inplace=True)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 24,
   "id": "e238f52f",
   "metadata": {},
   "outputs": [],
   "source": [
    "# df['Cpu'].value_counts()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 25,
   "id": "eb369924",
   "metadata": {},
   "outputs": [],
   "source": [
    "df['Cpu_name']=df['Cpu'].apply(lambda x : ' '.join(x.split()[:3]))"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 26,
   "id": "a01e463b",
   "metadata": {},
   "outputs": [],
   "source": [
    "# df['Cpu_name'].value_counts()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 27,
   "id": "2e133cd8",
   "metadata": {},
   "outputs": [],
   "source": [
    "def fetch_processor(text):\n",
    "    if text == 'Intel Core i7' or text == 'Intel Core i5' or text == 'Intel Core i3' or text == 'Intel Celeron Dual' : \n",
    "        return text\n",
    "    else :\n",
    "        if text.split()[0] == 'Intel':\n",
    "            return 'Other Intel Processor'\n",
    "        else :\n",
    "            return 'AMD Processor'"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 28,
   "id": "8c800f19",
   "metadata": {},
   "outputs": [],
   "source": [
    "df['Cpu_name']=df['Cpu_name'].apply(fetch_processor)\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 29,
   "id": "3dc915bd",
   "metadata": {},
   "outputs": [],
   "source": [
    "# df['Cpu_name'].value_counts().plot(kind='bar')"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 30,
   "id": "3d5234ab",
   "metadata": {},
   "outputs": [],
   "source": [
    "# sns.barplot(df['Cpu_name'],df['Price'])\n",
    "# plt.xticks(rotation='vertical')\n",
    "# plt.show()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 31,
   "id": "85fcceac",
   "metadata": {},
   "outputs": [],
   "source": [
    "df['Speed'] = df['Cpu'].apply(lambda x:x.split()[-1].split('GHz')[0]).astype(float)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 32,
   "id": "e900de26",
   "metadata": {},
   "outputs": [],
   "source": [
    "df['Cpu']=df['Cpu_name']"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 33,
   "id": "9584264a",
   "metadata": {},
   "outputs": [],
   "source": [
    "df.drop(columns='Cpu_name',inplace=True)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 34,
   "id": "9d4a1779",
   "metadata": {},
   "outputs": [],
   "source": [
    "# df['Ram'].value_counts().plot(kind='bar')"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 35,
   "id": "113d86b0",
   "metadata": {},
   "outputs": [],
   "source": [
    "# sns.barplot(df['Ram'],df['Price'])\n",
    "# plt.xticks(rotation='vertical')\n",
    "# plt.show()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 36,
   "id": "e16676cd",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "Memory\n",
       "256GB SSD                        412\n",
       "1TB HDD                          223\n",
       "500GB HDD                        132\n",
       "512GB SSD                        118\n",
       "128GB SSD +  1TB HDD              94\n",
       "128GB SSD                         76\n",
       "256GB SSD +  1TB HDD              73\n",
       "32GB Flash Storage                38\n",
       "2TB HDD                           16\n",
       "64GB Flash Storage                15\n",
       "512GB SSD +  1TB HDD              14\n",
       "1TB SSD                           14\n",
       "256GB SSD +  2TB HDD              10\n",
       "1.0TB Hybrid                       9\n",
       "256GB Flash Storage                8\n",
       "16GB Flash Storage                 7\n",
       "32GB SSD                           6\n",
       "180GB SSD                          5\n",
       "128GB Flash Storage                4\n",
       "512GB SSD +  2TB HDD               3\n",
       "16GB SSD                           3\n",
       "512GB Flash Storage                2\n",
       "1TB SSD +  1TB HDD                 2\n",
       "256GB SSD +  500GB HDD             2\n",
       "128GB SSD +  2TB HDD               2\n",
       "256GB SSD +  256GB SSD             2\n",
       "512GB SSD +  256GB SSD             1\n",
       "512GB SSD +  512GB SSD             1\n",
       "64GB Flash Storage +  1TB HDD      1\n",
       "1TB HDD +  1TB HDD                 1\n",
       "32GB HDD                           1\n",
       "64GB SSD                           1\n",
       "128GB HDD                          1\n",
       "240GB SSD                          1\n",
       "8GB SSD                            1\n",
       "508GB Hybrid                       1\n",
       "1.0TB HDD                          1\n",
       "512GB SSD +  1.0TB Hybrid          1\n",
       "256GB SSD +  1.0TB Hybrid          1\n",
       "Name: count, dtype: int64"
      ]
     },
     "execution_count": 36,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "df['Memory'].value_counts()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 37,
   "id": "dd26544f",
   "metadata": {},
   "outputs": [],
   "source": [
    "df['Memory'] = df['Memory'].astype(str).replace('\\.0', '', regex=True)\n",
    "df[\"Memory\"] = df[\"Memory\"].str.replace('GB', '')\n",
    "df[\"Memory\"] = df[\"Memory\"].str.replace('TB', '000')\n",
    "new = df[\"Memory\"].str.split(\"+\", n = 1, expand = True)\n",
    "\n",
    "df[\"first\"]= new[0]\n",
    "df[\"first\"]=df[\"first\"].str.strip()\n",
    "\n",
    "\n",
    "df[\"second\"]= new[1]\n",
    "\n",
    "df[\"Layer1HDD\"] = df[\"first\"].apply(lambda x: 1 if \"HDD\" in x else 0)\n",
    "df[\"Layer1SSD\"] = df[\"first\"].apply(lambda x: 1 if \"SSD\" in x else 0)\n",
    "df[\"Layer1Hybrid\"] = df[\"first\"].apply(lambda x: 1 if \"Hybrid\" in x else 0)\n",
    "df[\"Layer1Flash_Storage\"] = df[\"first\"].apply(lambda x: 1 if \"Flash Storage\" in x else 0)\n",
    "\n",
    "df['first'] = df['first'].str.replace(r'\\D', '')\n",
    "\n",
    "df[\"second\"].fillna(\"0\", inplace = True)\n",
    "\n",
    "df[\"Layer2HDD\"] = df[\"second\"].apply(lambda x: 1 if \"HDD\" in x else 0)\n",
    "df[\"Layer2SSD\"] = df[\"second\"].apply(lambda x: 1 if \"SSD\" in x else 0)\n",
    "df[\"Layer2Hybrid\"] = df[\"second\"].apply(lambda x: 1 if \"Hybrid\" in x else 0)\n",
    "df[\"Layer2Flash_Storage\"] = df[\"second\"].apply(lambda x: 1 if \"Flash Storage\" in x else 0)\n",
    "\n",
    "\n",
    "df['first'] = df['first'].apply(lambda x:x.split(' ')[0] )\n",
    "df['second'] = df['second'].str.replace(r'  ', '')\n",
    "df['second'] = df['second'].apply(lambda x:x.split(' ')[0] )\n",
    "\n",
    "df[\"first\"] = df[\"first\"].astype(int)\n",
    "df[\"second\"] = df[\"second\"].astype(int)\n",
    "\n",
    "\n",
    "\n",
    "df.head()\n",
    "\n",
    "df[\"HDD\"]=(df[\"first\"]*df[\"Layer1HDD\"]+df[\"second\"]*df[\"Layer2HDD\"])\n",
    "df[\"SSD\"]=(df[\"first\"]*df[\"Layer1SSD\"]+df[\"second\"]*df[\"Layer2SSD\"])\n",
    "df[\"Hybrid\"]=(df[\"first\"]*df[\"Layer1Hybrid\"]+df[\"second\"]*df[\"Layer2Hybrid\"])\n",
    "df[\"Flash_Storage\"]=(df[\"first\"]*df[\"Layer1Flash_Storage\"]+df[\"second\"]*df[\"Layer2Flash_Storage\"])\n",
    "\n",
    "df.drop(columns=['first', 'second', 'Layer1HDD', 'Layer1SSD', 'Layer1Hybrid',\n",
    "       'Layer1Flash_Storage', 'Layer2HDD', 'Layer2SSD', 'Layer2Hybrid',\n",
    "       'Layer2Flash_Storage'],inplace=True)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 39,
   "id": "a8d2e506",
   "metadata": {},
   "outputs": [],
   "source": [
    "\n",
    "df.drop(columns=['Hybrid','Flash_Storage'],inplace=True)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 40,
   "id": "a46c6ac6",
   "metadata": {},
   "outputs": [
    {
     "ename": "AttributeError",
     "evalue": "'DataFrame' object has no attribute 'second'",
     "output_type": "error",
     "traceback": [
      "\u001b[1;31m---------------------------------------------------------------------------\u001b[0m",
      "\u001b[1;31mAttributeError\u001b[0m                            Traceback (most recent call last)",
      "\u001b[1;32m~\\AppData\\Local\\Temp\\ipykernel_13292\\3910391168.py\u001b[0m in \u001b[0;36m?\u001b[1;34m()\u001b[0m\n\u001b[1;32m----> 1\u001b[1;33m \u001b[0mdf\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0msecond\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0munique\u001b[0m\u001b[1;33m(\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0m",
      "\u001b[1;32mc:\\Users\\Rajat\\AppData\\Local\\Programs\\Python\\Python311\\Lib\\site-packages\\pandas\\core\\generic.py\u001b[0m in \u001b[0;36m?\u001b[1;34m(self, name)\u001b[0m\n\u001b[0;32m   6200\u001b[0m             \u001b[1;32mand\u001b[0m \u001b[0mname\u001b[0m \u001b[1;32mnot\u001b[0m \u001b[1;32min\u001b[0m \u001b[0mself\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0m_accessors\u001b[0m\u001b[1;33m\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0;32m   6201\u001b[0m             \u001b[1;32mand\u001b[0m \u001b[0mself\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0m_info_axis\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0m_can_hold_identifiers_and_holds_name\u001b[0m\u001b[1;33m(\u001b[0m\u001b[0mname\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0;32m   6202\u001b[0m         ):\n\u001b[0;32m   6203\u001b[0m             \u001b[1;32mreturn\u001b[0m \u001b[0mself\u001b[0m\u001b[1;33m[\u001b[0m\u001b[0mname\u001b[0m\u001b[1;33m]\u001b[0m\u001b[1;33m\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[1;32m-> 6204\u001b[1;33m         \u001b[1;32mreturn\u001b[0m \u001b[0mobject\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0m__getattribute__\u001b[0m\u001b[1;33m(\u001b[0m\u001b[0mself\u001b[0m\u001b[1;33m,\u001b[0m \u001b[0mname\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0m",
      "\u001b[1;31mAttributeError\u001b[0m: 'DataFrame' object has no attribute 'second'"
     ]
    }
   ],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": 43,
   "id": "0d11314d",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "Gpu\n",
       "Intel HD          639\n",
       "Nvidia GeForce    368\n",
       "AMD Radeon        173\n",
       "Intel UHD          68\n",
       "Nvidia Quadro      31\n",
       "Intel Iris         14\n",
       "AMD FirePro         5\n",
       "AMD R4              1\n",
       "Nvidia GTX          1\n",
       "AMD R17M-M1-70      1\n",
       "Intel Graphics      1\n",
       "ARM Mali            1\n",
       "Name: count, dtype: int64"
      ]
     },
     "execution_count": 43,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "df['Gpu'].value_counts()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 42,
   "id": "22d62b9c",
   "metadata": {},
   "outputs": [],
   "source": [
    "df['Gpu'] =df['Gpu'].apply(lambda x: ' '.join(x.split()[:2]))"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 44,
   "id": "10abdf9a",
   "metadata": {},
   "outputs": [],
   "source": [
    "df = df[df['Gpu'] != 'ARM Mali']"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 45,
   "id": "027b27dd",
   "metadata": {},
   "outputs": [],
   "source": [
    "def change_gpu(i):\n",
    "    if i in ['AMD FirePro','AMD R4','Nvidia GTX','AMD R17M-M1-70','Intel Graphics']:\n",
    "        return 'Other'\n",
    "    else :\n",
    "        return i"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 46,
   "id": "368a3e89",
   "metadata": {},
   "outputs": [
    {
     "name": "stderr",
     "output_type": "stream",
     "text": [
      "C:\\Users\\Rajat\\AppData\\Local\\Temp\\ipykernel_13292\\1586382374.py:1: SettingWithCopyWarning: \n",
      "A value is trying to be set on a copy of a slice from a DataFrame.\n",
      "Try using .loc[row_indexer,col_indexer] = value instead\n",
      "\n",
      "See the caveats in the documentation: https://pandas.pydata.org/pandas-docs/stable/user_guide/indexing.html#returning-a-view-versus-a-copy\n",
      "  df['Gpu']=df['Gpu'].apply(change_gpu)\n"
     ]
    }
   ],
   "source": [
    "df['Gpu']=df['Gpu'].apply(change_gpu)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "053d8b7e",
   "metadata": {},
   "outputs": [],
   "source": [
    "# sns.barplot(df['Gpu'],df['Price'],estimator=np.median)\n",
    "# plt.xticks(rotation='vertical')\n",
    "# plt.show()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "0319a31e",
   "metadata": {},
   "outputs": [],
   "source": [
    "# df.OpSys.value_counts()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "545cc2ac",
   "metadata": {},
   "outputs": [],
   "source": [
    "# sns.barplot(x=df.OpSys,y=df.Price)\n",
    "# plt.xticks(rotation='vertical')\n",
    "# plt.show()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 47,
   "id": "bb8b947d",
   "metadata": {},
   "outputs": [],
   "source": [
    "def cat_os(inp):\n",
    "    if inp=='Windows 10' or inp=='Windows 7' or inp=='Windows 10 S':\n",
    "        return 'Windows'\n",
    "    elif inp=='macOS' or inp=='Mac OS X':\n",
    "        return 'Mac OS'\n",
    "    elif inp=='Android' or inp=='Chrome OS':\n",
    "        return 'Other'\n",
    "    else :\n",
    "        return inp"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 48,
   "id": "d4d1a058",
   "metadata": {},
   "outputs": [
    {
     "name": "stderr",
     "output_type": "stream",
     "text": [
      "C:\\Users\\Rajat\\AppData\\Local\\Temp\\ipykernel_13292\\1040093113.py:1: SettingWithCopyWarning: \n",
      "A value is trying to be set on a copy of a slice from a DataFrame.\n",
      "Try using .loc[row_indexer,col_indexer] = value instead\n",
      "\n",
      "See the caveats in the documentation: https://pandas.pydata.org/pandas-docs/stable/user_guide/indexing.html#returning-a-view-versus-a-copy\n",
      "  df['OpSys'] = df['OpSys'].apply(cat_os)\n"
     ]
    }
   ],
   "source": [
    "df['OpSys'] = df['OpSys'].apply(cat_os)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "32a334f5",
   "metadata": {},
   "outputs": [],
   "source": [
    "# sns.distplot(df['Weight'])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "ae371fc2",
   "metadata": {},
   "outputs": [],
   "source": [
    "# sns.scatterplot(x=df.Weight,y=df.Price)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "3c49049d",
   "metadata": {},
   "outputs": [],
   "source": [
    "# sns.heatmap(df.corr())"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 49,
   "id": "a8c05f6b",
   "metadata": {},
   "outputs": [
    {
     "name": "stderr",
     "output_type": "stream",
     "text": [
      "C:\\Users\\Rajat\\AppData\\Local\\Temp\\ipykernel_13292\\1067780064.py:1: SettingWithCopyWarning: \n",
      "A value is trying to be set on a copy of a slice from a DataFrame.\n",
      "Try using .loc[row_indexer,col_indexer] = value instead\n",
      "\n",
      "See the caveats in the documentation: https://pandas.pydata.org/pandas-docs/stable/user_guide/indexing.html#returning-a-view-versus-a-copy\n",
      "  df.Price =np.log(df.Price)\n"
     ]
    }
   ],
   "source": [
    "df.Price =np.log(df.Price)\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "f1f2f8b6",
   "metadata": {},
   "outputs": [],
   "source": [
    "# df.to_csv('cleaned_data')"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 50,
   "id": "c6eb9921",
   "metadata": {},
   "outputs": [],
   "source": [
    "import pickle\n",
    "X =df.drop(columns=['Price','Memory'])\n",
    "X.to_csv('clean_data')\n",
    "y = df['Price']\n",
    "from sklearn.model_selection import train_test_split\n",
    "X_train,X_test,y_train,y_test = train_test_split(X,y,random_state=2,test_size=0.15)\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 51,
   "id": "3befdc94",
   "metadata": {},
   "outputs": [],
   "source": [
    "# ! pip install xgboost\n",
    "from sklearn.compose import ColumnTransformer\n",
    "from sklearn.pipeline import Pipeline\n",
    "from sklearn.preprocessing import OneHotEncoder\n",
    "from sklearn.metrics import r2_score,mean_absolute_error\n",
    "from sklearn.linear_model import LinearRegression,Ridge,Lasso\n",
    "# from sklearn.neighbors import KNeighborsRegressor\n",
    "# from sklearn.tree import DecisionTreeRegressor\n",
    "from sklearn.ensemble import RandomForestRegressor,GradientBoostingRegressor,AdaBoostRegressor,ExtraTreesRegressor\n",
    "# from sklearn.svm import SVR\n",
    "# from xgboost import XGBRegressor"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "5e772add",
   "metadata": {},
   "outputs": [],
   "source": [
    "# random state  =157\n",
    "#110 n _ esti\n",
    "#0.49 max_fe"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 69,
   "id": "c999d593",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/html": [
       "<style>#sk-container-id-2 {color: black;}#sk-container-id-2 pre{padding: 0;}#sk-container-id-2 div.sk-toggleable {background-color: white;}#sk-container-id-2 label.sk-toggleable__label {cursor: pointer;display: block;width: 100%;margin-bottom: 0;padding: 0.3em;box-sizing: border-box;text-align: center;}#sk-container-id-2 label.sk-toggleable__label-arrow:before {content: \"▸\";float: left;margin-right: 0.25em;color: #696969;}#sk-container-id-2 label.sk-toggleable__label-arrow:hover:before {color: black;}#sk-container-id-2 div.sk-estimator:hover label.sk-toggleable__label-arrow:before {color: black;}#sk-container-id-2 div.sk-toggleable__content {max-height: 0;max-width: 0;overflow: hidden;text-align: left;background-color: #f0f8ff;}#sk-container-id-2 div.sk-toggleable__content pre {margin: 0.2em;color: black;border-radius: 0.25em;background-color: #f0f8ff;}#sk-container-id-2 input.sk-toggleable__control:checked~div.sk-toggleable__content {max-height: 200px;max-width: 100%;overflow: auto;}#sk-container-id-2 input.sk-toggleable__control:checked~label.sk-toggleable__label-arrow:before {content: \"▾\";}#sk-container-id-2 div.sk-estimator input.sk-toggleable__control:checked~label.sk-toggleable__label {background-color: #d4ebff;}#sk-container-id-2 div.sk-label input.sk-toggleable__control:checked~label.sk-toggleable__label {background-color: #d4ebff;}#sk-container-id-2 input.sk-hidden--visually {border: 0;clip: rect(1px 1px 1px 1px);clip: rect(1px, 1px, 1px, 1px);height: 1px;margin: -1px;overflow: hidden;padding: 0;position: absolute;width: 1px;}#sk-container-id-2 div.sk-estimator {font-family: monospace;background-color: #f0f8ff;border: 1px dotted black;border-radius: 0.25em;box-sizing: border-box;margin-bottom: 0.5em;}#sk-container-id-2 div.sk-estimator:hover {background-color: #d4ebff;}#sk-container-id-2 div.sk-parallel-item::after {content: \"\";width: 100%;border-bottom: 1px solid gray;flex-grow: 1;}#sk-container-id-2 div.sk-label:hover label.sk-toggleable__label {background-color: #d4ebff;}#sk-container-id-2 div.sk-serial::before {content: \"\";position: absolute;border-left: 1px solid gray;box-sizing: border-box;top: 0;bottom: 0;left: 50%;z-index: 0;}#sk-container-id-2 div.sk-serial {display: flex;flex-direction: column;align-items: center;background-color: white;padding-right: 0.2em;padding-left: 0.2em;position: relative;}#sk-container-id-2 div.sk-item {position: relative;z-index: 1;}#sk-container-id-2 div.sk-parallel {display: flex;align-items: stretch;justify-content: center;background-color: white;position: relative;}#sk-container-id-2 div.sk-item::before, #sk-container-id-2 div.sk-parallel-item::before {content: \"\";position: absolute;border-left: 1px solid gray;box-sizing: border-box;top: 0;bottom: 0;left: 50%;z-index: -1;}#sk-container-id-2 div.sk-parallel-item {display: flex;flex-direction: column;z-index: 1;position: relative;background-color: white;}#sk-container-id-2 div.sk-parallel-item:first-child::after {align-self: flex-end;width: 50%;}#sk-container-id-2 div.sk-parallel-item:last-child::after {align-self: flex-start;width: 50%;}#sk-container-id-2 div.sk-parallel-item:only-child::after {width: 0;}#sk-container-id-2 div.sk-dashed-wrapped {border: 1px dashed gray;margin: 0 0.4em 0.5em 0.4em;box-sizing: border-box;padding-bottom: 0.4em;background-color: white;}#sk-container-id-2 div.sk-label label {font-family: monospace;font-weight: bold;display: inline-block;line-height: 1.2em;}#sk-container-id-2 div.sk-label-container {text-align: center;}#sk-container-id-2 div.sk-container {/* jupyter's `normalize.less` sets `[hidden] { display: none; }` but bootstrap.min.css set `[hidden] { display: none !important; }` so we also need the `!important` here to be able to override the default hidden behavior on the sphinx rendered scikit-learn.org. See: https://github.com/scikit-learn/scikit-learn/issues/21755 */display: inline-block !important;position: relative;}#sk-container-id-2 div.sk-text-repr-fallback {display: none;}</style><div id=\"sk-container-id-2\" class=\"sk-top-container\"><div class=\"sk-text-repr-fallback\"><pre>OneHotEncoder()</pre><b>In a Jupyter environment, please rerun this cell to show the HTML representation or trust the notebook. <br />On GitHub, the HTML representation is unable to render, please try loading this page with nbviewer.org.</b></div><div class=\"sk-container\" hidden><div class=\"sk-item\"><div class=\"sk-estimator sk-toggleable\"><input class=\"sk-toggleable__control sk-hidden--visually\" id=\"sk-estimator-id-2\" type=\"checkbox\" checked><label for=\"sk-estimator-id-2\" class=\"sk-toggleable__label sk-toggleable__label-arrow\">OneHotEncoder</label><div class=\"sk-toggleable__content\"><pre>OneHotEncoder()</pre></div></div></div></div></div>"
      ],
      "text/plain": [
       "OneHotEncoder()"
      ]
     },
     "execution_count": 69,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "ohe = OneHotEncoder()\n",
    "temp_X = X.iloc[:,[0,1,2,4,5]]\n",
    "ohe.fit(temp_X)\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 64,
   "id": "9e618c6d",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<style scoped>\n",
       "    .dataframe tbody tr th:only-of-type {\n",
       "        vertical-align: middle;\n",
       "    }\n",
       "\n",
       "    .dataframe tbody tr th {\n",
       "        vertical-align: top;\n",
       "    }\n",
       "\n",
       "    .dataframe thead th {\n",
       "        text-align: right;\n",
       "    }\n",
       "</style>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>Company</th>\n",
       "      <th>TypeName</th>\n",
       "      <th>Cpu</th>\n",
       "      <th>Ram</th>\n",
       "      <th>Gpu</th>\n",
       "      <th>OpSys</th>\n",
       "      <th>Weight</th>\n",
       "      <th>TouchScreen</th>\n",
       "      <th>IPS</th>\n",
       "      <th>ppi</th>\n",
       "      <th>Speed</th>\n",
       "      <th>HDD</th>\n",
       "      <th>SSD</th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>0</th>\n",
       "      <td>Apple</td>\n",
       "      <td>Ultrabook</td>\n",
       "      <td>Intel Core i5</td>\n",
       "      <td>8</td>\n",
       "      <td>Intel Iris</td>\n",
       "      <td>Mac OS</td>\n",
       "      <td>1.37</td>\n",
       "      <td>0</td>\n",
       "      <td>1</td>\n",
       "      <td>226.983005</td>\n",
       "      <td>2.3</td>\n",
       "      <td>0</td>\n",
       "      <td>128</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1</th>\n",
       "      <td>Apple</td>\n",
       "      <td>Ultrabook</td>\n",
       "      <td>Intel Core i5</td>\n",
       "      <td>8</td>\n",
       "      <td>Intel HD</td>\n",
       "      <td>Mac OS</td>\n",
       "      <td>1.34</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>127.677940</td>\n",
       "      <td>1.8</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>2</th>\n",
       "      <td>HP</td>\n",
       "      <td>Notebook</td>\n",
       "      <td>Intel Core i5</td>\n",
       "      <td>8</td>\n",
       "      <td>Intel HD</td>\n",
       "      <td>No OS</td>\n",
       "      <td>1.86</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>141.211998</td>\n",
       "      <td>2.5</td>\n",
       "      <td>0</td>\n",
       "      <td>256</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>3</th>\n",
       "      <td>Apple</td>\n",
       "      <td>Ultrabook</td>\n",
       "      <td>Intel Core i7</td>\n",
       "      <td>16</td>\n",
       "      <td>AMD Radeon</td>\n",
       "      <td>Mac OS</td>\n",
       "      <td>1.83</td>\n",
       "      <td>0</td>\n",
       "      <td>1</td>\n",
       "      <td>220.534624</td>\n",
       "      <td>2.7</td>\n",
       "      <td>0</td>\n",
       "      <td>512</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>4</th>\n",
       "      <td>Apple</td>\n",
       "      <td>Ultrabook</td>\n",
       "      <td>Intel Core i5</td>\n",
       "      <td>8</td>\n",
       "      <td>Intel Iris</td>\n",
       "      <td>Mac OS</td>\n",
       "      <td>1.37</td>\n",
       "      <td>0</td>\n",
       "      <td>1</td>\n",
       "      <td>226.983005</td>\n",
       "      <td>3.1</td>\n",
       "      <td>0</td>\n",
       "      <td>256</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>...</th>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1298</th>\n",
       "      <td>Lenovo</td>\n",
       "      <td>2 in 1 Convertible</td>\n",
       "      <td>Intel Core i7</td>\n",
       "      <td>4</td>\n",
       "      <td>Intel HD</td>\n",
       "      <td>Windows</td>\n",
       "      <td>1.80</td>\n",
       "      <td>1</td>\n",
       "      <td>1</td>\n",
       "      <td>157.350512</td>\n",
       "      <td>2.5</td>\n",
       "      <td>0</td>\n",
       "      <td>128</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1299</th>\n",
       "      <td>Lenovo</td>\n",
       "      <td>2 in 1 Convertible</td>\n",
       "      <td>Intel Core i7</td>\n",
       "      <td>16</td>\n",
       "      <td>Intel HD</td>\n",
       "      <td>Windows</td>\n",
       "      <td>1.30</td>\n",
       "      <td>1</td>\n",
       "      <td>1</td>\n",
       "      <td>276.053530</td>\n",
       "      <td>2.5</td>\n",
       "      <td>0</td>\n",
       "      <td>512</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1300</th>\n",
       "      <td>Lenovo</td>\n",
       "      <td>Notebook</td>\n",
       "      <td>Intel Celeron Dual</td>\n",
       "      <td>2</td>\n",
       "      <td>Intel HD</td>\n",
       "      <td>Windows</td>\n",
       "      <td>1.50</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>111.935204</td>\n",
       "      <td>1.6</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1301</th>\n",
       "      <td>HP</td>\n",
       "      <td>Notebook</td>\n",
       "      <td>Intel Core i7</td>\n",
       "      <td>6</td>\n",
       "      <td>AMD Radeon</td>\n",
       "      <td>Windows</td>\n",
       "      <td>2.19</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>100.454670</td>\n",
       "      <td>2.5</td>\n",
       "      <td>1000</td>\n",
       "      <td>0</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1302</th>\n",
       "      <td>Asus</td>\n",
       "      <td>Notebook</td>\n",
       "      <td>Intel Celeron Dual</td>\n",
       "      <td>4</td>\n",
       "      <td>Intel HD</td>\n",
       "      <td>Windows</td>\n",
       "      <td>2.20</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>100.454670</td>\n",
       "      <td>1.6</td>\n",
       "      <td>500</td>\n",
       "      <td>0</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "<p>1302 rows × 13 columns</p>\n",
       "</div>"
      ],
      "text/plain": [
       "     Company            TypeName                 Cpu  Ram         Gpu  \\\n",
       "0      Apple           Ultrabook       Intel Core i5    8  Intel Iris   \n",
       "1      Apple           Ultrabook       Intel Core i5    8    Intel HD   \n",
       "2         HP            Notebook       Intel Core i5    8    Intel HD   \n",
       "3      Apple           Ultrabook       Intel Core i7   16  AMD Radeon   \n",
       "4      Apple           Ultrabook       Intel Core i5    8  Intel Iris   \n",
       "...      ...                 ...                 ...  ...         ...   \n",
       "1298  Lenovo  2 in 1 Convertible       Intel Core i7    4    Intel HD   \n",
       "1299  Lenovo  2 in 1 Convertible       Intel Core i7   16    Intel HD   \n",
       "1300  Lenovo            Notebook  Intel Celeron Dual    2    Intel HD   \n",
       "1301      HP            Notebook       Intel Core i7    6  AMD Radeon   \n",
       "1302    Asus            Notebook  Intel Celeron Dual    4    Intel HD   \n",
       "\n",
       "        OpSys  Weight  TouchScreen  IPS         ppi  Speed   HDD  SSD  \n",
       "0      Mac OS    1.37            0    1  226.983005    2.3     0  128  \n",
       "1      Mac OS    1.34            0    0  127.677940    1.8     0    0  \n",
       "2       No OS    1.86            0    0  141.211998    2.5     0  256  \n",
       "3      Mac OS    1.83            0    1  220.534624    2.7     0  512  \n",
       "4      Mac OS    1.37            0    1  226.983005    3.1     0  256  \n",
       "...       ...     ...          ...  ...         ...    ...   ...  ...  \n",
       "1298  Windows    1.80            1    1  157.350512    2.5     0  128  \n",
       "1299  Windows    1.30            1    1  276.053530    2.5     0  512  \n",
       "1300  Windows    1.50            0    0  111.935204    1.6     0    0  \n",
       "1301  Windows    2.19            0    0  100.454670    2.5  1000    0  \n",
       "1302  Windows    2.20            0    0  100.454670    1.6   500    0  \n",
       "\n",
       "[1302 rows x 13 columns]"
      ]
     },
     "execution_count": 64,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "X = X.drop(columns='Id')\n",
    "X"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 70,
   "id": "a4463db1",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "[array(['Acer', 'Apple', 'Asus', 'Chuwi', 'Dell', 'Fujitsu', 'Google',\n",
       "        'HP', 'Huawei', 'LG', 'Lenovo', 'MSI', 'Mediacom', 'Microsoft',\n",
       "        'Razer', 'Samsung', 'Toshiba', 'Vero', 'Xiaomi'], dtype=object),\n",
       " array(['2 in 1 Convertible', 'Gaming', 'Netbook', 'Notebook', 'Ultrabook',\n",
       "        'Workstation'], dtype=object),\n",
       " array(['AMD Processor', 'Intel Celeron Dual', 'Intel Core i3',\n",
       "        'Intel Core i5', 'Intel Core i7', 'Other Intel Processor'],\n",
       "       dtype=object),\n",
       " array(['AMD Radeon', 'Intel HD', 'Intel Iris', 'Intel UHD',\n",
       "        'Nvidia GeForce', 'Nvidia Quadro', 'Other'], dtype=object),\n",
       " array(['Linux', 'Mac OS', 'No OS', 'Other', 'Windows'], dtype=object)]"
      ]
     },
     "execution_count": 70,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "categories = ohe.categories_\n",
    "categories"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "d8d9e2b0",
   "metadata": {},
   "outputs": [],
   "source": [
    "# for i in range(1,200):\n",
    "#     X_train,X_test,y_train,y_test = train_test_split(X,y,random_state=157,test_size=0.15)\n",
    "#     step1 =ColumnTransformer(transformers=[\n",
    "#         ('col_trf',OneHotEncoder(sparse=False,drop='first',categories=categories),[0,1,2,4,5])\n",
    "#     ],remainder='passthrough')\n",
    "#     step2 = RandomForestRegressor(random_state=491,n_jobs=-1,n_estimators=114,max_features=0.31,max_depth=20)\n",
    "#     pipe =Pipeline([\n",
    "#             ('step1',step1),\n",
    "#             ('step2',step2)\n",
    "\n",
    "#         ])\n",
    "\n",
    "#     pipe.fit(X_train,y_train)\n",
    "#     y_pred = pipe.predict(X_test)\n",
    "#     print(i)\n",
    "#     print('R2 score',r2_score(y_test,y_pred))\n",
    "#     mse =mean_absolute_error(y_test,y_pred)\n",
    "#     print('mse',mse)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "f36b3a94",
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "R2 score 0.9441345134649242\n",
      "mse 0.11081596890322248\n"
     ]
    }
   ],
   "source": [
    "# X_train,X_test,y_train,y_test = train_test_split(X,y,random_state=157,test_size=0.15)\n",
    "# step1 =ColumnTransformer(transformers=[\n",
    "#     ('col_trf',OneHotEncoder(sparse=False,drop='first',categories=categories),[0,1,2,4,5])\n",
    "# ],remainder='passthrough')\n",
    "# step2 = RandomForestRegressor(random_state=491,n_jobs=-1,n_estimators=114,max_features=0.31,max_depth=20)\n",
    "# pipe =Pipeline([\n",
    "#         ('step1',step1),\n",
    "#         ('step2',step2)\n",
    "\n",
    "#     ])\n",
    "\n",
    "# pipe.fit(X_train,y_train)\n",
    "# y_pred = pipe.predict(X_test)\n",
    "# print('R2 score',r2_score(y_test,y_pred))\n",
    "# mse =mean_absolute_error(y_test,y_pred)\n",
    "# print('mse',mse)"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "ab899014",
   "metadata": {},
   "source": [
    "# linear Regression"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "434b62d9",
   "metadata": {},
   "outputs": [],
   "source": [
    "# step1 =ColumnTransformer(transformers=[\n",
    "#     ('col_trf',OneHotEncoder(sparse=False,drop='first'),[0,1,2,4,5])\n",
    "# ],remainder='passthrough')\n",
    "\n",
    "# step2 = LinearRegression()\n",
    "\n",
    "# pipe =Pipeline([\n",
    "#     ('step1',step1),\n",
    "#     ('step2',step2)\n",
    "    \n",
    "# ])\n",
    "\n",
    "# pipe.fit(X_train,y_train)\n",
    "# y_pred = pipe.predict(X_test)\n",
    "# print('R2 score',r2_score(y_test,y_pred))\n",
    "# mse =mean_absolute_error(y_test,y_pred)\n",
    "# print('mse',mse)\n"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "36ccf48b",
   "metadata": {},
   "source": [
    "# Ridge Regression"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "3a6e725f",
   "metadata": {},
   "outputs": [],
   "source": [
    "# step1 =ColumnTransformer(transformers=[\n",
    "#     ('col_trf',OneHotEncoder(sparse=False,drop='first'),[0,1,2,4,5])\n",
    "# ],remainder='passthrough')\n",
    "\n",
    "# step2 = Ridge(alpha=6)\n",
    "\n",
    "# pipe =Pipeline([\n",
    "#     ('step1',step1),\n",
    "#     ('step2',step2)\n",
    "    \n",
    "# ])\n",
    "\n",
    "# pipe.fit(X_train,y_train)\n",
    "# y_pred = pipe.predict(X_test)\n",
    "# print('R2 score',r2_score(y_test,y_pred))\n",
    "# mse =mean_absolute_error(y_test,y_pred)\n",
    "# print('mse',mse)\n"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "76678cf8",
   "metadata": {},
   "source": [
    "# Lasso Regression"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "0236da6a",
   "metadata": {},
   "outputs": [],
   "source": [
    "# step1 =ColumnTransformer(transformers=[\n",
    "#     ('col_trf',OneHotEncoder(sparse=False,drop='first'),[0,1,2,4,5])\n",
    "# ],remainder='passthrough')\n",
    "\n",
    "# step2 = Lasso(alpha=0.0001)\n",
    "\n",
    "# pipe =Pipeline([\n",
    "#     ('step1',step1),\n",
    "#     ('step2',step2)\n",
    "    \n",
    "# ])\n",
    "\n",
    "# pipe.fit(X_train,y_train)\n",
    "# y_pred = pipe.predict(X_test)\n",
    "# print('R2 score',r2_score(y_test,y_pred))\n",
    "# mse =mean_absolute_error(y_test,y_pred)\n",
    "# print('mse',mse)"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "140a94d5",
   "metadata": {},
   "source": [
    "# KNeighborsRegressor\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "c66457d7",
   "metadata": {},
   "outputs": [],
   "source": [
    "# step1 =ColumnTransformer(transformers=[\n",
    "#     ('col_trf',OneHotEncoder(sparse=False,drop='first'),[0,1,2,4,5])\n",
    "# ],remainder='passthrough')\n",
    "\n",
    "# step2 = KNeighborsRegressor(n_neighbors=5)\n",
    "\n",
    "# pipe =Pipeline([\n",
    "#     ('step1',step1),\n",
    "#     ('step2',step2)\n",
    "    \n",
    "# ])\n",
    "\n",
    "# pipe.fit(X_train,y_train)\n",
    "# y_pred = pipe.predict(X_test)\n",
    "# print('R2 score',r2_score(y_test,y_pred))\n",
    "# mse =mean_absolute_error(y_test,y_pred)\n",
    "# print('mse',mse)"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "78626e1b",
   "metadata": {},
   "source": [
    "# Decision Tree"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "17efb5f4",
   "metadata": {},
   "outputs": [],
   "source": [
    "# step1 =ColumnTransformer(transformers=[\n",
    "#     ('col_trf',OneHotEncoder(sparse=False,drop='first'),[0,1,2,4,5])\n",
    "# ],remainder='passthrough')\n",
    "\n",
    "# step2 = DecisionTreeRegressor(max_depth=8)\n",
    "\n",
    "# pipe =Pipeline([\n",
    "#     ('step1',step1),\n",
    "#     ('step2',step2)\n",
    "    \n",
    "# ])\n",
    "\n",
    "# pipe.fit(X_train,y_train)\n",
    "# y_pred = pipe.predict(X_test)\n",
    "# print('R2 score',r2_score(y_test,y_pred))\n",
    "# mse =mean_absolute_error(y_test,y_pred)\n",
    "# print('mse',mse)"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "4bbc2f7c",
   "metadata": {},
   "source": [
    "# SVM"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "9e56827d",
   "metadata": {},
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "892a8ef2",
   "metadata": {},
   "outputs": [],
   "source": [
    "# step1 =ColumnTransformer(transformers=[\n",
    "#     ('col_trf',OneHotEncoder(sparse=False,drop='first'),[0,1,2,4,5])\n",
    "# ],remainder='passthrough')\n",
    "\n",
    "# step2 = SVR(kernel='rbf',C=10000,epsilon=0.2)\n",
    "\n",
    "# pipe =Pipeline([\n",
    "#     ('step1',step1),\n",
    "#     ('step2',step2)\n",
    "    \n",
    "# ])\n",
    "\n",
    "# pipe.fit(X_train,y_train)\n",
    "# y_pred = pipe.predict(X_test)\n",
    "# print('R2 score',r2_score(y_test,y_pred))\n",
    "# mse =mean_absolute_error(y_test,y_pred)\n",
    "# print('mse',mse)"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "c9d9ff29",
   "metadata": {},
   "source": [
    "# Random forest"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "02d4cd56",
   "metadata": {},
   "outputs": [],
   "source": [
    "# step1 =ColumnTransformer(transformers=[\n",
    "#     ('col_trf',OneHotEncoder(sparse=False,drop='first'),[0,1,2,4,5])\n",
    "# ],remainder='passthrough')\n",
    "\n",
    "# step2 = RandomForestRegressor(n_estimators=100,\n",
    "#                               random_state=3,\n",
    "#                               max_samples=0.5,\n",
    "#                               max_features=0.75,\n",
    "#                               max_depth=15)\n",
    "\n",
    "# pipe =Pipeline([\n",
    "#     ('step1',step1),\n",
    "#     ('step2',step2)\n",
    "    \n",
    "# ])\n",
    "\n",
    "# pipe.fit(X_train,y_train)\n",
    "# y_pred = pipe.predict(X_test)\n",
    "# print('R2 score',r2_score(y_test,y_pred))\n",
    "# mse =mean_absolute_error(y_test,y_pred)\n",
    "# print('mse',mse)"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "78f23f8b",
   "metadata": {},
   "source": [
    "# Extra Tree "
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "86d66f5c",
   "metadata": {},
   "outputs": [],
   "source": [
    "# step1 =ColumnTransformer(transformers=[\n",
    "#     ('col_trf',OneHotEncoder(sparse=False,drop='first'),[0,1,2,4,5])\n",
    "# ],remainder='passthrough')\n",
    "\n",
    "# step2 = ExtraTreesRegressor(n_estimators=100,\n",
    "#                               random_state=3,\n",
    "#                               max_samples=0.5,\n",
    "#                               max_features=0.75,\n",
    "#                               max_depth=15)\n",
    "\n",
    "# pipe =Pipeline([\n",
    "#     ('step1',step1),\n",
    "#     ('step2',step2)\n",
    "    \n",
    "# ])\n",
    "\n",
    "# pipe.fit(X_train,y_train)\n",
    "# y_pred = pipe.predict(X_test)\n",
    "# print('R2 score',r2_score(y_test,y_pred))\n",
    "# mse =mean_absolute_error(y_test,y_pred)\n",
    "# print('mse',mse)"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "dd8aaa3e",
   "metadata": {},
   "source": [
    "# Ada"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "ae86c712",
   "metadata": {},
   "outputs": [],
   "source": [
    "# step1 =ColumnTransformer(transformers=[\n",
    "#     ('col_trf',OneHotEncoder(sparse=False,drop='first'),[0,1,2,4,5])\n",
    "# ],remainder='passthrough')\n",
    "\n",
    "# step2 = AdaBoostRegressor(n_estimators=15,learning_rate=1.0)\n",
    "\n",
    "# pipe =Pipeline([\n",
    "#     ('step1',step1),\n",
    "#     ('step2',step2)\n",
    "    \n",
    "# ])\n",
    "\n",
    "# pipe.fit(X_train,y_train)\n",
    "# y_pred = pipe.predict(X_test)\n",
    "# print('R2 score',r2_score(y_test,y_pred))\n",
    "# mse =mean_absolute_error(y_test,y_pred)\n",
    "# print('mse',mse)"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "13d90a60",
   "metadata": {},
   "source": [
    "# Gradient Boosting"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "a6565bcd",
   "metadata": {},
   "outputs": [],
   "source": [
    "\n",
    "#     step1 =ColumnTransformer(transformers=[\n",
    "#         ('col_trf',OneHotEncoder(sparse=False,drop='first'),[0,1,2,4,5])\n",
    "#     ],remainder='passthrough')\n",
    "\n",
    "#     step2 = GradientBoostingRegressor(n_estimators=i)\n",
    "\n",
    "#     pipe =Pipeline([\n",
    "#         ('step1',step1),\n",
    "#         ('step2',step2)\n",
    "\n",
    "#     ])\n",
    "\n",
    "#     pipe.fit(X_train,y_train)\n",
    "#     y_pred = pipe.predict(X_test)\n",
    "#     print(i)\n",
    "#     print('R2 score',r2_score(y_test,y_pred))\n",
    "#     mse =mean_absolute_error(y_test,y_pred)\n",
    "#     print('mse',mse)\n",
    "    "
   ]
  },
  {
   "cell_type": "markdown",
   "id": "e8f3f1d1",
   "metadata": {},
   "source": [
    "# XG Boost"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "d24f2ed4",
   "metadata": {},
   "outputs": [],
   "source": [
    "# step1 =ColumnTransformer(transformers=[\n",
    "#     ('col_trf',OneHotEncoder(sparse=False,drop='first'),[0,1,2,4,5])\n",
    "# ],remainder='passthrough')\n",
    "\n",
    "# step2 = XGBRegressor(n_estimators=45,max_depth=5,learning_rate=0.5)\n",
    "\n",
    "# pipe =Pipeline([\n",
    "#     ('step1',step1),\n",
    "#     ('step2',step2)\n",
    "    \n",
    "# ])\n",
    "\n",
    "# pipe.fit(X_train,y_train)\n",
    "# y_pred = pipe.predict(X_test)\n",
    "# print('R2 score',r2_score(y_test,y_pred))\n",
    "# mse =mean_absolute_error(y_test,y_pred)\n",
    "# print('mse',mse)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "a222801a",
   "metadata": {},
   "outputs": [],
   "source": [
    "# from sklearn.ensemble import VotingRegressor,StackingRegressor\n",
    "\n",
    "# step1 = ColumnTransformer(transformers=[\n",
    "#     ('col_tnf',OneHotEncoder(sparse=False,drop='first'),[0,1,2,4,5])\n",
    "# ],remainder='passthrough')\n",
    "\n",
    "\n",
    "# rf = RandomForestRegressor(n_estimators=350,random_state=3,max_samples=0.5,max_features=0.75,max_depth=15)\n",
    "# gbdt = GradientBoostingRegressor(n_estimators=100,max_features=0.5)\n",
    "# xgb = XGBRegressor(n_estimators=25,learning_rate=0.3,max_depth=5)\n",
    "# et = ExtraTreesRegressor(n_estimators=100,random_state=3,max_samples=0.5,max_features=0.75,max_depth=10)\n",
    "\n",
    "# step2 = VotingRegressor([('rf', rf), ('gbdt', gbdt), ('xgb',xgb), ('et',et)],weights=[5,1,1,1])\n",
    "\n",
    "# pipe = Pipeline([\n",
    "#     ('step1',step1),\n",
    "#     ('step2',step2)\n",
    "# ])\n",
    "\n",
    "# pipe.fit(X_train,y_train)\n",
    "\n",
    "# y_pred = pipe.predict(X_test)\n",
    "\n",
    "# print('R2 score',r2_score(y_test,y_pred))\n",
    "# print('MAE',mean_absolute_error(y_test,y_pred))"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "82a12396",
   "metadata": {},
   "outputs": [],
   "source": [
    "# for i in range(0,500):\n",
    "#     step1 =ColumnTransformer(transformers=[\n",
    "#         ('col_trf',OneHotEncoder(sparse=False,drop='first'),[0,1,2,4,5])\n",
    "#     ],remainder='passthrough')\n",
    "\n",
    "#     step2 = RandomForestRegressor(random_state=273,n_jobs=-1,n_estimators=97,max_features=0.15,max_depth=25)\n",
    "\n",
    "#     pipe =Pipeline([\n",
    "#         ('step1',step1),\n",
    "#         ('step2',step2)\n",
    "\n",
    "#     ])\n",
    "\n",
    "#     pipe.fit(X_train,y_train)\n",
    "#     y_pred = pipe.predict(X_test)\n",
    "#     print(i/10)\n",
    "#     print('R2 score',r2_score(y_test,y_pred))\n",
    "#     mse =mean_absolute_error(y_test,y_pred)\n",
    "#     print('mse',mse)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 66,
   "id": "40bfa043",
   "metadata": {},
   "outputs": [],
   "source": [
    "# random_state\n",
    "# 273\n",
    "# R2 score 0.9110870643688667\n",
    "# mse 0.13978206060672282\n",
    "# n_estimators\n",
    "# 97\n",
    "# R2 score 0.9118627814519411\n",
    "# mse 0.13956279145844386\n",
    "# max_features\n",
    "# 0.15\n",
    "from sklearn.preprocessing import StandardScaler,MinMaxScaler,MaxAbsScaler\n",
    "ss = StandardScaler()\n",
    "mms = MinMaxScaler()\n",
    "mas = MaxAbsScaler()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 67,
   "id": "ab7a07e5",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<style scoped>\n",
       "    .dataframe tbody tr th:only-of-type {\n",
       "        vertical-align: middle;\n",
       "    }\n",
       "\n",
       "    .dataframe tbody tr th {\n",
       "        vertical-align: top;\n",
       "    }\n",
       "\n",
       "    .dataframe thead th {\n",
       "        text-align: right;\n",
       "    }\n",
       "</style>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>Company</th>\n",
       "      <th>TypeName</th>\n",
       "      <th>Cpu</th>\n",
       "      <th>Ram</th>\n",
       "      <th>Gpu</th>\n",
       "      <th>OpSys</th>\n",
       "      <th>Weight</th>\n",
       "      <th>TouchScreen</th>\n",
       "      <th>IPS</th>\n",
       "      <th>ppi</th>\n",
       "      <th>Speed</th>\n",
       "      <th>HDD</th>\n",
       "      <th>SSD</th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>0</th>\n",
       "      <td>Apple</td>\n",
       "      <td>Ultrabook</td>\n",
       "      <td>Intel Core i5</td>\n",
       "      <td>8</td>\n",
       "      <td>Intel Iris</td>\n",
       "      <td>Mac OS</td>\n",
       "      <td>1.37</td>\n",
       "      <td>0</td>\n",
       "      <td>1</td>\n",
       "      <td>226.983005</td>\n",
       "      <td>2.3</td>\n",
       "      <td>0</td>\n",
       "      <td>128</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1</th>\n",
       "      <td>Apple</td>\n",
       "      <td>Ultrabook</td>\n",
       "      <td>Intel Core i5</td>\n",
       "      <td>8</td>\n",
       "      <td>Intel HD</td>\n",
       "      <td>Mac OS</td>\n",
       "      <td>1.34</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>127.677940</td>\n",
       "      <td>1.8</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>2</th>\n",
       "      <td>HP</td>\n",
       "      <td>Notebook</td>\n",
       "      <td>Intel Core i5</td>\n",
       "      <td>8</td>\n",
       "      <td>Intel HD</td>\n",
       "      <td>No OS</td>\n",
       "      <td>1.86</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>141.211998</td>\n",
       "      <td>2.5</td>\n",
       "      <td>0</td>\n",
       "      <td>256</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>3</th>\n",
       "      <td>Apple</td>\n",
       "      <td>Ultrabook</td>\n",
       "      <td>Intel Core i7</td>\n",
       "      <td>16</td>\n",
       "      <td>AMD Radeon</td>\n",
       "      <td>Mac OS</td>\n",
       "      <td>1.83</td>\n",
       "      <td>0</td>\n",
       "      <td>1</td>\n",
       "      <td>220.534624</td>\n",
       "      <td>2.7</td>\n",
       "      <td>0</td>\n",
       "      <td>512</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>4</th>\n",
       "      <td>Apple</td>\n",
       "      <td>Ultrabook</td>\n",
       "      <td>Intel Core i5</td>\n",
       "      <td>8</td>\n",
       "      <td>Intel Iris</td>\n",
       "      <td>Mac OS</td>\n",
       "      <td>1.37</td>\n",
       "      <td>0</td>\n",
       "      <td>1</td>\n",
       "      <td>226.983005</td>\n",
       "      <td>3.1</td>\n",
       "      <td>0</td>\n",
       "      <td>256</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "</div>"
      ],
      "text/plain": [
       "  Company   TypeName            Cpu  Ram         Gpu   OpSys  Weight  \\\n",
       "0   Apple  Ultrabook  Intel Core i5    8  Intel Iris  Mac OS    1.37   \n",
       "1   Apple  Ultrabook  Intel Core i5    8    Intel HD  Mac OS    1.34   \n",
       "2      HP   Notebook  Intel Core i5    8    Intel HD   No OS    1.86   \n",
       "3   Apple  Ultrabook  Intel Core i7   16  AMD Radeon  Mac OS    1.83   \n",
       "4   Apple  Ultrabook  Intel Core i5    8  Intel Iris  Mac OS    1.37   \n",
       "\n",
       "   TouchScreen  IPS         ppi  Speed  HDD  SSD  \n",
       "0            0    1  226.983005    2.3    0  128  \n",
       "1            0    0  127.677940    1.8    0    0  \n",
       "2            0    0  141.211998    2.5    0  256  \n",
       "3            0    1  220.534624    2.7    0  512  \n",
       "4            0    1  226.983005    3.1    0  256  "
      ]
     },
     "execution_count": 67,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "X.head()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 71,
   "id": "4b668342",
   "metadata": {},
   "outputs": [
    {
     "name": "stderr",
     "output_type": "stream",
     "text": [
      "c:\\Users\\Rajat\\AppData\\Local\\Programs\\Python\\Python311\\Lib\\site-packages\\sklearn\\preprocessing\\_encoders.py:975: FutureWarning: `sparse` was renamed to `sparse_output` in version 1.2 and will be removed in 1.4. `sparse_output` is ignored unless you leave `sparse` to its default value.\n",
      "  warnings.warn(\n"
     ]
    },
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "R2 score 0.9444086882577916\n",
      "mse 0.11049927149909575\n"
     ]
    }
   ],
   "source": [
    "X_train,X_test,y_train,y_test = train_test_split(X,y,random_state=157,test_size=0.15)\n",
    "step1 =ColumnTransformer(transformers=[\n",
    "    ('col_trf',OneHotEncoder(sparse=False,drop='first',categories=categories),[0,1,2,4,5])\n",
    "],remainder='passthrough')\n",
    "step2 = RandomForestRegressor(random_state=491,n_jobs=-1,n_estimators=114,max_features=0.31,max_depth=20)\n",
    "pipe =Pipeline([\n",
    "        ('step1',step1),\n",
    "        ('step2',step2),\n",
    "    ])\n",
    "\n",
    "pipe.fit(X_train,y_train)\n",
    "y_pred = pipe.predict(X_test)\n",
    "print('R2 score',r2_score(y_test,y_pred))\n",
    "mse =mean_absolute_error(y_test,y_pred)\n",
    "print('mse',mse)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "b6c10a8a",
   "metadata": {},
   "outputs": [],
   "source": [
    "import pickle\n",
    "pickle.dump(pipe,open('model.pkl','wb'))"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "a3fce123",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "3.3289032563777248"
      ]
     },
     "execution_count": 1557,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "np.sqrt(11.08159689032222)"
   ]
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3 (ipykernel)",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.11.5"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 5
}
