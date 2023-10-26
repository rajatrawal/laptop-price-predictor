import streamlit as st
import pickle
import pandas as pd
import numpy as np
pipe = pickle.load(open('model.pkl','rb'))
df = pd.read_csv('clean_data.csv')
st.title('Laptop Price Predictor')

#brand
brand = st.selectbox('Brand',df['Company'].unique())

# type of laptop
type = st.selectbox('Type',df['TypeName'].unique())

#Ram
ram = st.selectbox('Ram',sorted(list(df['Ram'].unique())))

#Weight
weigth = st.number_input('Weight In KG',min_value=0)

#Touchscreen
touchscreen = st.selectbox('Touchscreen',['Yes','No'])

#IPS
ips = st.selectbox('IPS Display',['Yes','No'])

#Screen Size
inch = st.number_input('Screen Size In Inch',min_value=1)
#resolution
resolution = st.selectbox('Screen Resolution',['1920x1080','1366x768','1600x900','3840x2160','3200x1800','2880x1800','2560x1600','2560x1440','2304x1440'])
# tpi = resolution/inch

#cpu
cpu =st.selectbox('CPU',df['Cpu'].unique())

#hdd
hdd =st.number_input('HDD In GB',min_value=0)

#ssd
ssd =st.number_input('SSD In GB',min_value=0)

#gpu
gpu =st.selectbox('GPU',df['Gpu'].unique())

#os
os =st.selectbox('OS',df['OpSys'].unique())

#speed
speed =st.selectbox('Speed In GHz',sorted(df['Speed'].unique()))

if st.button('Predict Price'):
    ppi = None
    if touchscreen =='Yes':
        touchscreen=1
    else :
       touchscreen =0
    if ips=='Yes' :
        ips=1
    else :
        ips=0
    x_resolution = int(resolution.split('x')[0])**2
    y_resolution = int(resolution.split('x')[1])**2
    ppi = (x_resolution+y_resolution)**0.5/inch
    query = np.array([brand,type,cpu,ram,gpu,os,weigth,touchscreen,ips,ppi,speed,hdd,ssd])
    query=query.reshape(1,13)
    prediction =pipe.predict(query)
    st.title(f'Price For Laptop Will Be Rs. {np.round(np.exp(prediction[0]),0)}')