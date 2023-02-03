void deleteNode(Node *node)
{
   node->data = node->next->data;
   Node *temp = node->next;
   
   node->next = node->next->next;
   
   free(temp);
   
   // time and space complexity: O(1)
}