FROM alpine:3.14

# Install Nginx and dependencies
RUN apk update && apk add nginx
RUN mkdir -p /run/nginx

# Remove default Nginx configuration file
RUN rm /etc/nginx/nginx.conf

# Copy your custom Nginx configuration file
COPY conf/nginx.conf /etc/nginx/nginx.conf

# Expose the necessary ports
EXPOSE 80 443

# Set the entry point command
CMD ["nginx", "-g", "daemon off;"]
