FROM node:11.15.0

WORKDIR /client

RUN npm i npm@latest -g

COPY package.json package-lock.json /client/
RUN npm install && npm cache clean --force
ENV PATH /client/node_modules/.bin:$PATH

RUN npm install -g serve

COPY . /client/

RUN npm run build
CMD serve -s build -l 3000
