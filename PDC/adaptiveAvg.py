# ------------------------------------------------------------- 1st imp ----------------------------------------------------------------

# def adaptive_average(new_value, previous_avg, alpha):
#     """
#     Calculates the adaptive/over average for the new value using the previous average and alpha.

#     Args:
#     - new_value: float, the new value to be added to the average
#     - previous_avg: float, the previous average
#     - alpha: float, the smoothing factor. A higher value of alpha will give more weight to the new value.

#     Returns:
#     - float, the new average
#     """
#     return alpha * new_value + (1 - alpha) * previous_avg

# # Initialize the first value as the previous average
# previous_avg = 10

# # Set the smoothing factor
# alpha = 0.5

# # Generate some sample data
# data = [10, 20, 30, 40, 50]

# # Compute the adaptive/over average for each data point
# for new_value in data:
#     previous_avg = adaptive_average(new_value, previous_avg, alpha)
#     print("New value: {}, New average: {}".format(new_value, previous_avg))


# ------------------------------------------------------------- 2nd Imp -------------------------------------------------------
# import random

# # Define the number of nodes in the system
# NUM_NODES = 3

# # Define the possible values that the nodes can propose
# POSSIBLE_VALUES = [1, 2, 3, 4, 5]


# class Node:
#     def __init__(self, node_id):
#         self.id = node_id
#         self.proposed_value = None
#         self.decided_value = None

#     def propose_value(self):
#         # Randomly choose a value from the list of possible values
#         self.proposed_value = random.choice(POSSIBLE_VALUES)
#         print(f"Node {self.id} has proposed the value {self.proposed_value}")

#     def receive_proposed_value(self, value, sender_id):
#         # Check if the received value is higher than the current proposed value
#         if self.proposed_value is None or value > self.proposed_value:
#             self.proposed_value = value
#             print(
#                 f"Node {self.id} has updated its proposed value to {self.proposed_value} based on the proposal from Node {sender_id}")
#         else:
#             print(
#                 f"Node {self.id} has ignored the proposal from Node {sender_id} because its current proposed value is already higher")

#     def decide_value(self):
#         # Once all nodes have proposed a value, choose the highest proposed value as the decided value
#         self.decided_value = max(node.proposed_value for node in nodes)
#         print(f"Node {self.id} has decided on the value {self.decided_value}")

#     def receive_decided_value(self, value, sender_id):
#         # Check if the received decided value is different than the current decided value
#         if self.decided_value is None or value != self.decided_value:
#             self.decided_value = value
#             print(
#                 f"Node {self.id} has updated its decided value to {self.decided_value} based on the decision from Node {sender_id}")
#         else:
#             print(
#                 f"Node {self.id} has ignored the decision from Node {sender_id} because its current decided value is already the same")


# # Create the nodes in the system
# nodes = [Node(node_id) for node_id in range(1, NUM_NODES+1)]

# # Simulate the proposal phase
# for node in nodes:
#     node.propose_value()
#     for other_node in nodes:
#         if other_node.id != node.id:
#             other_node.receive_proposed_value(node.proposed_value, node.id)

# # Simulate the decision phase
# for node in nodes:
#     node.decide_value()
#     for other_node in nodes:
#         if other_node.id != node.id:
#             other_node.receive_decided_value(node.decided_value, node.id)


#  ------------------------------------------------------- 3rd IMP ------------------------------------------------

# import random
# import time

# alpha = 0.5
# beta = 1.5
# gamma = 0.5

# temperatures = [20.0, 22.0, 23.0]
# global_avg = sum(temperatures) / len(temperatures)

# for i in range(10):
#     local_temps = [t + random.uniform(-1, 1) for t in temperatures]
#     local_avg = sum(local_temps) / len(local_temps)

#     global_avg = (1 - alpha) * global_avg + alpha * local_avg
#     overshoot = global_avg - local_avg
#     if overshoot > 0:
#         dampening_factor = (1 - gamma) ** overshoot
#         global_avg = global_avg + beta * dampening_factor * overshoot

#     for j, temp in enumerate(local_temps):
#         print(
#             f"Node {j}: local temp = {temp:.2f}, global temp = {global_avg:.2f}")

#     time.sleep(60)
