#include <rti/rti_literature.h>

#include <vcl_iostream.h>
#include <vcl_vector.h>
#include <vcl_string.h>
#include <vul/vul_string.h>
#include <rti/rti_book_sptr.h>
#include <rti/rti_book.h>
#include <vector>

rti_literature::rti_literature()
{
  is_empty_ = true;
}

rti_literature::~rti_literature()
{}

bool
rti_literature::find(vcl_string in_title, int& idx)
{
  // if the dictictionary is empty, return right away
  if (books_.empty()) {
    idx = 0;
    return false;
  }

  vul_string_downcase(in_title);
  vcl_string title_lowercase;
  //find position for the exact search using bisection search (iterative version) or return the position the word should be found.
  int imax = int(books_.size()-1);
  int imin = 0;
  while (imax >= imin) {
    idx = (imax+imin)/2; // calculate the midpoint for roughly equal partition
    if(books_[idx]->title_downcase() == in_title) {
      return true; // key found at index imid
    }
    else if (books_[idx]->title_downcase() < in_title)// determine which subarray to search
      imin = idx + 1; // change min index to search upper subarray
    else imax = idx - 1; // change max index to search lower subarray
  }

  if (books_[idx]->title_downcase() < in_title) idx++; 
  return false;// key was not found
}

//find(.) should be called first to find out the pos for insertion. Books are ordered by title
void 
rti_literature::insert(rti_book_sptr book, int pos) 
{
  // if the new word should be at the end of list
  if (pos == books_.size()) books_.push_back(book); 
  else { // if the new word should be inserted elsewhere
    books_.push_back(books_.back());
    for (int i = int(books_.size())-2; i > pos; i--)
    {
      books_[i] = books_[i-1]; //push the entry to the right
    }
    books_[pos] = book;
  }
 
  is_empty_ = false;

}

//find(.) should be called first to find out the pos for replacement. Books are ordered by title
void 
rti_literature::replace(rti_book_sptr book, int pos) 
{
  books_[pos] = book;
 
  is_empty_ = false;

}

//*****New Code
void
rti_literature::remove(rti_book_sptr book, int pos)
{
	if (books_.empty())
	{
		is_empty_ = true;
	}
	else
	{
		books_.erase(books_.begin() + (pos - 1));
		if (books_.size() != 0)
		{
			is_empty_ = false;
		}
		else
		{
			is_empty_ = true;
		}
	}
}

rti_book_sptr
rti_literature::getBook(vcl_string isbn)
{
	for(int i = 0; i < books_.size(); i++)
	{
		if(books_.at(i)->isbn() == isbn)
		{
			return books_.at(i);
		}
	}
	return NULL;
}

std::vector<rti_book_sptr>
rti_literature::getAllBooks()
{
    return books_;
}
//*****New Code

void
rti_literature::push_back(rti_book_sptr word)
{ 
  books_.push_back(word); 
}


XMLError
rti_literature::read_xml(const vcl_string& xml_filename)
{
  books_.clear();
  is_empty_ = true;

	XMLDocument xmlDoc;
    
  //Parse the resource
  XMLError eResult = xmlDoc.LoadFile( xml_filename.c_str() );
  XMLCheckResult(eResult);

	/*Get the root element node */
  XMLElement * pRoot = xmlDoc.RootElement();
	books_.reserve(1000);
  XMLElement* pElement = pRoot->FirstChildElement("Book");
  while (pElement != nullptr) {
    rti_book_sptr book = new rti_book();
    book->read_xml_node(pElement);
    books_.push_back(book);
    pElement = pElement->NextSiblingElement("Book");
  }

  if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;
  is_empty_ = false;
  return XML_SUCCESS;
}

XMLError 
rti_literature::write_xml(vcl_string xml_filename)
{
  XMLDocument xmlDoc;
  XMLElement* root_node = xmlDoc.NewElement( "Literature" );
  root_node->SetAttribute("count",(int)books_.size());
  xmlDoc.InsertFirstChild( root_node );

  for (unsigned int i = 0; i<books_.size(); i++) {
    XMLElement * wElement = xmlDoc.NewElement("Book");
    books_[i]->write_xml_node(xmlDoc, wElement);
    root_node->InsertEndChild(wElement);
  }

  XMLError eResult = xmlDoc.SaveFile( xml_filename.c_str() );
  XMLCheckResult(eResult);
  return eResult;
}
