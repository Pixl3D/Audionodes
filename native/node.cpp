#include "node.hpp"

Node::Node(size_t input_count, size_t output_count, bool is_sink) :
    is_sink(is_sink),
    input_count(input_count),
    output_count(output_count),
    mark_deletion(false)
{
  input_values.resize(input_count);
  old_input_values.resize(input_count);
}

bool Node::get_is_sink() { return is_sink; }
size_t Node::get_input_count() { return input_count; }
void Node::set_input_value(int index, float value) {
  std::lock_guard<std::mutex> lock(input_values_mutex);
  input_values[index] = value;
}
float Node::get_input_value(int index) {
  std::lock_guard<std::mutex> lock(input_values_mutex);
  return input_values[index];
}
void Node::copy_input_values(Node *old_node) {
  input_values = old_node->input_values;
  old_input_values = old_node->old_input_values;
}
