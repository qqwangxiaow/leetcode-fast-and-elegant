//using ostringstream to serialize (inseart)
//using istringstream to deserialize (read)
//using # to represent null node
//
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
private:
    void serialize(TreeNode *root,ostringstream &out)
    {
        if(root)
        {
            out<<root->val<<' ';
            serialize(root->left,out);
            serialize(root->right,out);
        }
        else
        {
            out<<"# ";
        }
    }
    TreeNode *deserialize(istringstream &in)
    {
        string str;
        in>>str;
        if(str=="#")
        {
            return nullptr;
        }
        else
        {
            TreeNode *root=new TreeNode(stoi(str));
            root->left=deserialize(in);
            root->right=deserialize(in);
            return root;
        }

    }
};