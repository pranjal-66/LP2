def chatbot():
    print("🤖 Welcome to Customer Support Chatbot!")
    print("Type 'bye' to exit.\n")

    while True:
        user = input("You: ").lower()

        if user == "hello" or user == "hi":
            print("Bot: Hello! How can I help you today?")

        elif "product" in user:
            print("Bot: We have mobiles, laptops, and headphones available.")

        elif "price" in user:
            print("Bot: Please tell me the product name for pricing information.")

        elif "order" in user:
            print("Bot: Please provide your order ID to check status.")

        elif "delivery" in user:
            print("Bot: Delivery usually takes 3 to 5 business days.")

        elif "return" in user:
            print("Bot: Products can be returned within 7 days of delivery.")

        elif "payment" in user:
            print("Bot: We support UPI, Debit Card, Credit Card, and Net Banking.")

        elif user == "bye":
            print("Bot: Thank you for visiting. Have a great day!")
            break

        else:
            print("Bot: Sorry, I didn't understand. Please try again.")


chatbot()