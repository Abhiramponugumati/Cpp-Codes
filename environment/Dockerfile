FROM python:3.12-slim

WORKDIR /app

RUN apt-get update && apt-get install -y --no-install-recommends python3-pip && rm -rf /var/lib/apt/lists/*
RUN pip3 install uv

COPY data/sales.csv /app/data/sales.csv

RUN mkdir -p /app/output
